CC=gcc
TARGET=sockets

all:
	$(CC) sockets.c socket/common.c socket/client.c socket/server.c -o $(TARGET)

clean:
	rm $(TARGET)