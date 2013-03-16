#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#define FIFO_NAME "My_FIFO"

int main()
{
        char s[300];
        int num, fd;
        cout<<"Waiting for reader process to initilize..."<<endl;
        fd=open(FIFO_NAME, O_RDONLY);
        cout<<"Got a writer process..."<<endl;
        while(1)
        {
                if((num=read(fd, s, sizeof(s)))==-1)
                        perror("read");
                else
                {
                	if(num==0)
                	{
                		cout<<"Writer process has exited."<<endl;
                		close(fd);
                		return 0;
                	}
                        s[num]='\0';
                        cout<<"Receiver read "<<num<<" bytes: \""<<s<<"\""<<endl;
                        
                }
        }
}
