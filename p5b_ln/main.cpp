#include <iostream>
#include<string.h>
#include <errno.h>

using namespace std;

int main(int argc, char * argv[])
{
        if(argc!=3 && argc!=4)
        {
                cout<<"Usage: "<<argv[0]<<" [-s] <src_path> <dest_path>\n\n";
                return 0;
        }
        if(strcmp(argv[1],"-s")!=0)
        {
                if(link(argv[1],argv[2])==-1)
                {
                        cout<<"Hard link failed. Error number: "<<errno<<"\n";
                        cout<<strerror(errno)<<"\n";
                }
                else
                        cout<<"Hardlink between "<<argv[1]<<" and "<<argv[2]<<" has been created\n\n";
        }
        else
        {
                if(symlink(argv[2],argv[3])==-1)
                {
                        cout<<"\nSoft link failed. Error number: "<<errno<<"\n";
                        cout<<strerror(errno)<<"\n";
                }
                else
                        cout<<"Symbolic link created: "<<argv[3]<<" --> "<<argv[2]<<"\n\n";
        }
}
