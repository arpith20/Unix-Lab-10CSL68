#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
        pid_t pid;
        char cmd[50];
        if((pid=fork())<0)
        {
                perror("fork");
                return -1;
        }
        else if(pid==0)
        {
                cout<<"\nProcess id of parent:\t"<<getppid();
                cout<<"\nProcess id of child:\t"<<getpid()<<"\n\n";
                _exit(0);
        }
        else
        {
                sprintf(cmd,"ps -l %d",pid);
                system(cmd);
                sleep(20);
        }
        return 0;
}



