#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

char input[60], stmt[3][60];
int cur,len,i,j;

void gen()
{
    int L1=101,L2=102,L3=103;
    printf("if %s goto %d \n", stmt[0],L1);
    printf("\n goto %d \n", L2);
    printf("%d : %s \n", L1,stmt[1]);
    if(cur<3)
    {
        printf("%d : STOP \n",L2);
    }
    else
    {
        printf("goto %d \n",L3);
        printf("%d : %s \n", L2, stmt[2]);
        printf("%d : STOP \n",L3);
    }
}
int main()
{
    printf("format of if statement \n example: \n");
    printf("if (a<b) then (s=a); \n");
    printf("if (a<b) then (s=a) else (s=b); \n");
    printf("Enter the statement \n");
    gets(input);
    len=strlen(input);
    int index=0;
    for(i=0;i<len && input[i]!=';';i++)
    {
	if(input[i]=='(')
	{
        	index=0;
        	for(j=i; input[j-1]!=')';j++)
	            stmt[cur][index++]=input[j];
        	cur++;
        	i=j;
    	}
    }
    gen();
    return 0;
}
