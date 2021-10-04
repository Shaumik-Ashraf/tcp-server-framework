//server - utils.c

#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>

#include"server.h"
#include"utils.h"


extern config_t config;



int getpacket(int sfd, char buf[], ssize_t buf_size) {
  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  ssize_t nread;

  peer_addr_len = sizeof(struct sockaddr_storage);
  nread = recvfrom(sfd, buf, buf_size, 0, (struct sockaddr*)&peer_addr, &peer_addr_len);

  if( nread == -1 ) {
    int errsv = errno;
    fprintf(stderr, "ERROR getpacket(): %s\n", strerror(errsv));
    return(1);
  }
  else {
    status = getnameinfo((struct sockaddr*)&peer_addr, peer_addr_len, peer, NI_MAXHOST, service)
    if(status) {
      fprintf(stderr, "WARNING getnameinfo(): %s\n", gai_strerror(s));
      memset(peer, 0, NI_MAXHOST);
      memset(service, 0, NI_MAXSERV);
    }
    else {
      fprintf(stderr, "INFO recieved packet of %zd bytes from %s:%s\n", nread, service, peer);
    }
  }

  return(0);
}

int putpacket(int sfd, char buf[], size_t len) {
  if( len != sendto(sfd, buf, len, 0, (struct sockaddr*)&peer_addr, peer_addr_len) ) {
    int errsv = errno;
    fprintf(stderr, "ERROR putpacket(): %s\n", strerror(errsv));
    return(1);
  }
}

int putpacketl(int sfd, char buf[]) {
  return putpacket(sfd, buf, strlen(buf));
}


int setsocketin(int sfd) {
  if( dup2(sfd, stdin) == -1 ) {
    int errsv = errno;
    fprintf(stderr, "ERROR setsocketin(): %s\n", strerror(errno));
    return(1);
  }
  return(0);
}

int setsocketout(int sfd) {
  if( dup2(sfd, stdout) == -1 ) {
    int errsv = errno;
    fprintf(stderr, "ERROR setsocketout(): %s\n", strerror(errno));
    return(1);
  }
  return(0);
}
