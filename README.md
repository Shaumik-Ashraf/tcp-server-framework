# TCP Server Framework

A barebones TCP Server Framework in POSIX C; removes boilerplate code and uses loop paradigm.

## How To Use
 - copy files into project
 - edit init(), loop(), and quit() in server.c
 - `make`
 - `./server`

## File Spec
 - server.c : EDIT THIS FILE ONLY
 - server.h : contains declarations, documentation, and configurations you may want to look at
 - utils.h : useful functions declarations and documentation
 - utils.c : implementations of functions in utils.h
 - main.c : contains main() **DO NOT EDIT MAIN DIRECTLY**
 - server.mk : makefile 

## Todo
 - better signal handling?
 - config file?
 - systemd integration?
