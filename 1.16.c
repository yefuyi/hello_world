#include<stdio.h>
void max(int a,int b,int c)
{
	int d,e,f;
	d = (d = a > b ? a: b) > c ? d : c;
	f = (f =  a < b ? a : b) < c ? f : c;
	if(a != d & a!= f) e = a;
	else if(b != d && b != f) e = b;
	else e = c;
	printf("%3d%3d%3d",d,e,f);
}
int main()
{
	int a,b,c;
	printf("输入三个不同大小的整数: ");
	scanf("%d%d%d",&a,&b,&c);
	max(a,b,c);
	return 0;
	
}
