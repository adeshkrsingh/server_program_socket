#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void writeData(char fileName[], char data[]) {
    FILE *p;

    // int x = *(&fileName + 1) - fileName;
    int x = strlen(fileName);

	char fName[1000];
    fileName = "";
    strcpy( fName, fileName);
	strcat(fName, ".txt");
    p = fopen("log.txt", "a");


    if(p == NULL)
    {
        printf("Not allowed");
        exit(0);
    }

    fprintf(p, data);
    fprintf(p, "\n");
    fclose(p);
}