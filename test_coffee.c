#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main (int argc, char *argv[])
{
    char *my_env[] = {"FOOD=coffee",NULL};
    if(execle("./coffee","./coffee","donut",NULL,my_env) == -1)
    {
        fprintf(stderr,"Can't run process 0: %s\n",strerror(errno));
        return 1;
    }
    return 0;
}
