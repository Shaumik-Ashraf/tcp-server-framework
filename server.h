//server - server.h

#ifndef SERVER_H
#define SERVER_H

#include<sys/types.h>
#include<sys/socket.h>

typedef struct {

  int port;
  struct sigaction if_sigint;

} config_t;

config_t config;

void init(int argc, char* argv[], char* env[], int sfd);
void loop(int argc, char* argv[], char* env[], int sfd);
void quit(void);

#endif
