#define _POSIX_SOURCE
#include <iostream>
#include<stdio.h>
#include<unistd.h>
#include<limits.h>

using namespace std;

int main(int argc,char *argv[])
{

        long ct,cn,pn,char_n,of;
        if((ct=sysconf(_SC_CLK_TCK))==1)
        {
                perror("sysconf");
                return 0;
        }
        else
        {
                cout<<"\nNo of clock ticks: "<<ct;
        }
        if((of=(sysconf(_SC_OPEN_MAX)))==-1)
        {
                perror("sysconf");
                return 0;
        }
        else
        {
                cout<<"\nMax number of open files: "<<of;
        }
        if((cn=(sysconf(_POSIX_CHILD_MAX)))==-1)
        {
                perror("sysconf");
                return 0;
        }
        else
        {
                cout<<"\nMax number of child: "<<cn;
        }
        if((pn=(pathconf("/",_PC_PATH_MAX)))==-1)
        {
                perror("pathconf");
                return 0;
        }
        else
        {
                cout<<"\nMax Path "<<pn;
        }
        if((char_n=(pathconf("/",_PC_NAME_MAX)))==-1)
        {
                perror("pathconf");
                return 0;
        }
        else
        {
                cout<<"\nMax number of characters is "<<char_n<<"\n\n";
        }
        return 0;
}
