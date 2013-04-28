#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

static void charatatime(char str[])
{
	char* ptr;
	int i;
	setbuf(stdout,NULL);
	for(ptr=str; i=*ptr++;)
		putc(i,stdout);
}

int main()
{
	pid_t p;
	if((p=fork())<0)
	{
		perror("fork");
		return -1;
	}
	else if(p==0)
		charatatime("OUTPUT IS FROM CHILD\n");
	else
		charatatime("OUTPUT IS FROM PARENT\n");
	exit(0);
}
