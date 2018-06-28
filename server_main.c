#include "header_description.h"

int main(int argc, char const *argv[])
{
    int master_socket, new_socket = 0;
    struct sockaddr_in serveraddress;
    struct sockaddr_in clientaddress;
    int addrlen = sizeof(serveraddress);
    int max_clients = 3, client_socket[3];

    int max_sd, opt=1, msgFromClient, sd, valread;
    fd_set readfds;
    struct timeval now;
    int rc;
    char buffer[1024];
    int i = 0;
    int numsocks = 0;


    for (i = 0; i < max_clients; i++)  
    {  
        client_socket[i] = 0;  
    }

    // create socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("master socket failed");
        exit(EXIT_FAILURE);
    }
    // attach socket
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }


    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = INADDR_ANY;
    serveraddress.sin_port = htons((atoi(getenv("SERVER_PORT") )));
    // bind socket
    if (bind(master_socket, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // listen socket
    if (listen(master_socket, MAX_PENDING_CONNECTION) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    rc = gettimeofday(&now, NULL);
    if(rc==0) { printf("time = %u.%06u ", now.tv_sec, now.tv_usec); }



    while(1) {
        FD_ZERO(&readfds);
        FD_SET(master_socket, &readfds);
        if(new_socket >  0 ) {
            FD_SET(new_socket, &readfds);
            if(master_socket > new_socket) {
                max_sd = master_socket;
            } else {
                max_sd = new_socket;
            }
        } else {
            max_sd = master_socket;
        }

        // int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
        if( select(max_sd + 1, &readfds, NULL, NULL, NULL)  ) {
            printf("select executed \n");
        } else {
            printf("select not executed");
        }
        // printf("%d", isSelected);



        if (FD_ISSET(master_socket, &readfds))
        {
            if(new_socket == 0) {
                printf(" now calling accept function...\n");
                if ((new_socket = accept(master_socket, (struct sockaddr *)&clientaddress, (socklen_t *)&addrlen)) < 0)
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                FD_SET(new_socket, &readfds);
                printf("socket accept : %d \n", new_socket);
            } 
       }

       if(FD_ISSET(new_socket, &readfds)) {
           printf("now calling read function ..\n");
            if (msgFromClient = read(new_socket, buffer, 1024))
            {
                printf("There is a message from client: %s \n", buffer);
            } else {
                new_socket = 0;
                printf("message reading failed \n");
            }
       }

    }

    return 0;
}