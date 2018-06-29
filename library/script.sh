gcc -c createNode.c addNode.c printList.c
ar -crv mylib.a createNode.o addNode.o printList.o
ar -t mylib.a
#!gcc -static -I ./ -o main main.c ./mylib.a
#!gcc -I ./ -o main main.c ./mylib.a
#!./main
