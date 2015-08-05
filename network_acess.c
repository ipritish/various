#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>

void error (char *msg)
{
    fprintf(stderr,"%s: %s\n",msg,strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *advice[] = {
        "Take smaller bites\r\n",
        "Go for tight jeans\r\n",
        "One word : inappropriate\r\n",
        "Just for today\r\n",
        "You rethink the haircut\r\n"
    };

    int listener_d = socket(PF_INET,SOCK_STREAM,0);

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener_d,(struct sockaddr *) &name, sizeof(name)) == -1)
    {
        int reuse = 1;
        if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        {
            error ("Can't reuse the port : ");
        }
    }

    listen(listener_d,10);
    
    puts("Waiting for the connection");

    while(1)
    {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept(listener_d,(struct sockaddr *) &client_addr, &address_size);
        char *msg = advice[rand() % 5];
        send (connect_d,msg,strlen(msg),0);
        close (connect_d);

    }

    return 0;
}
