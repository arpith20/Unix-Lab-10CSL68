#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

using namespace std;

void alarm_handler(int signum)
{
	cout<<"\nAlarm time elapsed!!!\n";
}

void func(int dur)
{
	signal(SIGALRM,alarm_handler);
	alarm(dur);
	pause();
}

int main()
{
	int dur;
	cout<<"\nEnter duration: ";
	cin>>dur;
	func(dur);
	return 0;
}
