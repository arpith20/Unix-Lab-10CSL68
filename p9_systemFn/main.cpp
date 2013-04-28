#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


using namespace std;

int mysystem(const char *strcmd)
{
        int status;
        pid_t pid;
        if(strcmd==NULL)
                return -1;
        if((pid=fork())<0)
        {
                perror("fork");
                status=-1;
        }
        else if(pid==0)
        {
                execl("/bin/sh","sh","-c",strcmd,(char *)0);
                status=0;
        }
        else
        {
                cout<<"PID= "<<pid<<endl;
                while(waitpid(pid,&status,0)==-1)
                {
                        perror("waitpid");
                        return -1;
                }
        }
        return status;
}

int main(int argc, char *argv)
{
        int status;
        char cmd[50];
        do
        {
                cout<<"myshell> ";
                gets(cmd);
                if((status=mysystem(cmd))<0)
                        cout<<"Error Encountered\n";
        }while(strcmp(cmd,"exit"));
        return 0;
}
