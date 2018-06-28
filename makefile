CC=gcc
all:tcp_server
tcp_server:fileHandling.c server_main.c
	${CC} -o tcp_server -lpthread fileHandling.c server_main.c
