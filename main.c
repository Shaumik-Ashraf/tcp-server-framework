//server - main.c
//DO NOT EDIT THIS; EDIT server.c INSTEAD


#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>

#include"server.h"
#include"utils.h"


static void sighandler()


int main(int argc, char* argv[], char* env[]) {

  at_exit(quit);
  signal(SIGINT, sighandler);


  struct addrinfo hints;
  struct addrinfo *results;
  struct addrinfo *rp;
  int sfd;
  int status;
  //struct sockaddr_storage peer_addr;
  //socklen_t peer_addr_len;
  //ssize_t nread;
  //char buf[ config.buf_size ];
  char peer[NI_MAXHOST];
  char service[NI_MAXSERV];

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;     //ipv4 || ipv6
  hints.ai_scoktype = SOCK_STREAM; //tcp
  hints.ai_flags = AI_PASSIVE;     //wildcard IP address
  hints.ai_protocol = 0;           //any protocol
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  //construct host addr info
  status = getaddrinfo(NULL, config.port, &hints, &results);
  if( status ) {
    fprintf(stderr, "ERROR getaddrinfo(): %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  //iterate through socket types (ie: tcp ipv4, tcp ipv6) until successful bind
  for(rp = result; rp != NULL; rp = rp->ai_next) {
    sfd = socket(rp->ai_family, rp->ai_socktype, ap->ai_protocol);
    if( sfd == - 1) {
      int errsv = errno;
      fprintf(stderr, "WARNING socket(): %s\n", strerror(errsv));
      continue;
    }

    if( bind(sfd, rp->ai_addr, rp->ai_addrlen)==0 ) {
      break;
    }

    close(sfd);
  }

  //tie up loose ends
  if( rp == NULL ) {
    fprintf(stderr, "ERROR Failed to bind to socket\n");
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(result);

  //run init from server.c
  init(argc, argv, env, sfd);

  //server loop
  for(;;) {
    loop(argc, argv, env, sfd);
  }

  //in case there is a glitch in the matrix
  close(sfd);
  exit(EXIT_SUCCESS);
}
