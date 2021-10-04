//server - server.c

#include"server.h"

extern config_t config;


#include<stdio.h>
#include<unistd.h>
/* additional libraries here */

#define MAX 255


/* code here will run after server is binded to socket, but before reading any packets */
void init(int argc, char* argv[], char* env[], int sfd) {
  fprintf("Starting server on port %d with pid %d\n", config.port, getpid());

  //server setup code here

}


/* code here will run indefinitely; make sure to manage your memory */
void loop(int argc, char* argv[], char* env[], int sfd) {

  char input[MAX];
  char output[MAX];

  if( !getpacket(sfd, input, MAX) ) {
    goto EXCEPTION;
  }

  //echo server: (replace with real work here)
  snprintf(output, MAX, "Echo: %s", input);
  putpacketl(sfd, output);


  if(0) {
  EXCEPTION:
      putpacketl(sfd, "Internal Server Error\n");
  }

}


/* code here will be run upon exit() or SIGINT */
void quit(void) {
  fprintf(stderr, "Exiting server\n");

  //at_exit code here

}
