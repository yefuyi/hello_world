#include<stdio.h>
#define MAXINT 10
int Fun(int t)
{
	if(t == 0)
	return 1;
	else return t * 2 *Fun(t - 1);
}
int main()
{
	int a[MAXINT] ;
	int i;
	for( i = 0; i < MAXINT ; i++)
	{
		a[i] = Fun(i);
	}
	for(i = 0; i< MAXINT; i++)
	{
		printf("%d! * 2 ^%d =  %d\n",i, i ,a[i]);
	}
	return 0;
}
