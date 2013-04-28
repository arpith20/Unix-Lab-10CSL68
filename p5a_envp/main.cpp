#include <iostream>

using namespace std;

int main(int argc, char *argv, char *envp[])
{
        int index;
        for(index=0; envp[index]!='\0';index++)
        {
                cout<<envp[index]<<endl;
        }
}
