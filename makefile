CC=gcc
all:tcp_server
tcp_server:fileHandling.c server_main.c
	${CC} -I ./ -o tcp_server server_main.c ./library/libLinkedList.a
