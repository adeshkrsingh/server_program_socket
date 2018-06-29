#include "header_description.h"


int main(int argc, char const *argv[])
{
    int master_socket, new_socket = 0;
    struct sockaddr_in serveraddress;
    struct sockaddr_in clientaddress;
    int addrlen = sizeof(serveraddress);
    int max_clients = NUM_CLIENT, client_socket[NUM_CLIENT];

    int max_sd, opt=1, msgFromClient, sd, valread;
    fd_set readfds;
    time_t timer;
    char timeBuffer[26];
    time(&timer);
    // tm_info = localtime(&timer);
    // strftime(timeBuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    struct tm* tm_info;

    struct timeval timeout;
    // int rc;
    char buffer[BUFFER_LENGTH];
    int i = 0;
    int numsocks = 0;


    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

     node* clientList[max_clients];
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
    // client_socket[0] = master_socket;
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

    // rc = gettimeofday(&now, NULL);
    // if(rc==0) { printf("time = %u.%06u ", now.tv_sec, now.tv_usec); }



    while(1) {
        //printf("while loop \n");
        FD_ZERO(&readfds);
        FD_SET(master_socket, &readfds);

        max_sd = master_socket;
        for (i = 0; i < max_clients; i++)  
        {
            if(client_socket[i] != 0) {
                 FD_SET(client_socket[i], &readfds);
            }
            if(client_socket[i] > max_sd ) {
                max_sd = client_socket[i];
            }
        }

        //printf("while loop \n");

        // int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
        if( select(max_sd + 1, &readfds, NULL, NULL, NULL)  ) {
             printf("select executed \n");
        } else {
             printf("select not executed");
        }



        if (FD_ISSET(master_socket, &readfds))
        {
                printf(" now calling accept function...\n");
                if ((new_socket = accept(master_socket, (struct sockaddr *)&clientaddress, (socklen_t *)&addrlen)) < 0)
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                 FD_SET(new_socket, &readfds);
                for(i = 0; i< max_clients; i++) {
                    int x1 = client_socket[i];
                    if( x1 == 0 ) {
                        client_socket[i] = new_socket;
                        // createLinkedList("list_name");
                         createLinkedList(clientList[i]);
                        break;
                    }
                }
                printf("socket accept : %d \n", new_socket);
       }

       for(i = 0; i< max_clients; i++) {
           sd = client_socket[i];
           if( (sd != 0) ) {
               strcpy(buffer, "");
               if(FD_ISSET(sd, &readfds)) {
                    tm_info = localtime(&timer);
                    strftime(timeBuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
                    printf("now calling read function ..\n");
                        if (msgFromClient = read(sd, buffer, BUFFER_LENGTH))
                        {
                            // addListNode("list_name", "value");
                             clientList[i]=addNode(clientList[i],buffer);
                            printf("There is a message from client: %s %s \n", timeBuffer, buffer);
                        } else {
                            sd = 0;
                            client_socket[i] = 0;
                            printf("message reading failed \n");
                        }
                }
           } else {
           }
       }




       // printLinkedList("list_name")
       //printList(clientList[0]);

    }

    return 0;
}