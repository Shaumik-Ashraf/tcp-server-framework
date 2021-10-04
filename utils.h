//server - utils.h

#ifndef UTILS_H
#define UTILS_H

#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>


int getpacket(int sfd, char buf[], ssize_t buf_size);

int putpacket(int sfd, char buf[], size_t len);

int putpacketl(int sfd, char buf[]);

int setsocketin(int sfd);

int setsocketout(int sfd);


#endif
