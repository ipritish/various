#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void diediedie (int sig)
{
    puts("Goodbye Cruel World....\n");
    exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}

int main()
{
    if (catch_signal(SIGINT,diediedie) == -1)
    {
        fprintf(stderr,"Can't map the handler");
        exit(2);
    }
    
    char name[20];
    printf("Enter the name\n");
    fgets(name,20,stdin);
    printf("Hello %s\n",name);
    return 0;
}
