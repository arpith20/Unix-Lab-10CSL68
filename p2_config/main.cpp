#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309l
#include <iostream>
#include<unistd.h>

using namespace std;

int main()
{
        #ifdef _POSIX_JOB_CONTROL
                cout<<"_POSIX_JOB_CONTROL: \t This system supports job control!"<<endl;
        #else
                cout<<"_POSIX_JOB_CONTROL: \t Job control is not supported"<<endl;
        #endif
        #ifdef _POSIX_SAVED_IDS
                cout<<"_POSIX_SAVED_IDS: \t This system supports saved setUID and setGID"<<endl;
        #else
                cout<<"_POSIX_SAVED_IDS is not suppported"<<endl;
        #endif
        #ifdef _POSIX_CHOWN_RESTRICTED
                cout<<"_POSIX_CHOWN_RESTRICTED: Chown option is: "<<_POSIX_CHOWN_RESTRICTED<<endl;
        #else
                cout<<"_POSIX_CHOWN_RESTRICTED: \tNot supported"<<endl;
        #endif
        #ifdef _POSIX_NO_TRUNC
                cout<<"_POSIX_NO_TRUNC: \t Pathname truncate option is: "<<_POSIX_NO_TRUNC<<endl;
        #else
                cout<<"_POSIX_NO_TRUNC: \t Not supported"<<endl;
        #endif
        #ifdef _POSIX_VDISABLE
                cout<<"_POSIX_VDISABLE: \t Disable character for terminal files is: "<<_POSIX_VDISABLE<<endl;
        #else
                cout<<"_POSIX_VDISABLE: \t Not supported"<<endl;
        #endif
}


