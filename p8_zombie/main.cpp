#include <iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

using namespace std;

int main()
{
        pid_t pid1, pid2;
        char cmd[50];
        cout<<"Parent P has the process id: "<<getpid()<<endl;
        if((pid1=fork())<0)
        {
                perror("fork");
                return -1;
        }
        else if(pid1==0)
        {
                cout<<"Child proess p1 has the process id: "<<getpid()<<endl;
                if((pid2=fork())<0)
                {
                        perror("fork");
                        return -1;
                }
                else if(pid2==0)
                {
                        cout<<"Grand child p2 has the process id: "<<getpid()<<endl;
                        sleep(20);
                }
                else
                {
                        _exit(0);
                }
        }
        else
        {
                waitpid(pid1,NULL,0);
                return 0;
        }
}
