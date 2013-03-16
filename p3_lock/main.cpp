#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[])
{
        int fd;
        struct flock fLock;
        char buf[80]={""};
        if((fd=open(argv[1],O_RDWR))==-1)
        {
                perror("open");
                return -1;
        }
        fLock.l_type=F_WRLCK;
        fLock.l_whence=SEEK_END;
        fLock.l_start=-100;
        fLock.l_len=100;
        while(fcntl(fd, F_SETLK,&fLock)==-1)
        {
                while(fcntl(fd,F_GETLK,&fLock)!=1)
                {
                        cout<<argv[1]<<" is locked by the process "<<fLock.l_pid<<" from "<<fLock.l_start<<" for "<<fLock.l_len<<" bytes for "<<(fLock.l_type==F_WRLCK?"write":"read")<<endl;
                        return 1;
                }
        }
        cout<<"\nLock aquired on file: "<<argv[1]<<" by process with id "<<getpid()<<endl;
        sleep(20);
        lseek(fd,-50,SEEK_END);
        if(read(fd,buf,50)==-1)
                perror("read");
        else
        {
                cout<<"\nReading 50 bytes of the file\n";
                cout<<buf;
                cout<<endl;
        }
        fLock.l_type=F_UNLCK;
        fLock.l_whence=SEEK_SET;
        fLock.l_start=0;
        fLock.l_len=0;
        if(fcntl(fd,F_SETLK,&fLock)==-1)
                perror("fcntl");
        else
                cout<<endl<<argv[1]<<" unlocked by process "<<getpid()<<endl;
        return 0;
}
