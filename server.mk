all: main.o server.o utils.o
	gcc -o server main.o server.o utils.o

main.o: main.c server.h utils.h
	gcc -c main.c

server.o: server.c server.h
	gcc -c server.c

utils.o: utils.c utils.h
	gcc -c utils.c

run:
	./server

clean:
	rm *.o
