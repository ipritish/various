#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main (int argc , char *argv[])
{
    char *feeds[] = {"http://www.cnn.com/rss/celebs.xml",
                     "http://www.rollingstone.com/rock.xml",
                     "http://travel.cnn.com/rss.xml"};
    int times = 3;
    char *phrase;
    int i;
    for (i=0;i<times;i++)
    {
        char var[255];
        sprintf(var,"RSS_FEED=%s",feeds[i]);
        char *vars[] = {var,NULL};
        pid_t pid = fork();
        if (pid == -1)
        {
            fprintf(stderr,"Can't fork process: %s\n",strerror(errno));
            return 1;
        }
        if (!pid)
        {
            fprintf(stderr,"In child Process...\n");
            if (execle("/usr/bin/python","/usr/bin/python","./rssgossip.py",
               phrase,NULL,vars) == -1)
            {
                fprintf(stderr,"Can't run script: %s\n",strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}

