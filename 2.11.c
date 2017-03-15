/*
本代码包含的功能:
	1、插入元素a到表A
	2、初始化表
	3、打印表
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15	//A
#define MAX 100

void Create_List(int a[],int n)		//创建顺序表
{
	int i;
	printf("输入一个含有10个元素的递增有序顺序表: ");
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	a[0] = n;
	for(i = 1; i <= n - 1; i++)	//判断是否为有序递增的表
	{
		if( a[i] >= a[i + 1])
		{
			printf("输入的表不合法！\n");
			return;
		}
	}
}

void Print(int a[])		//打印链表
{
	int i;
	printf("\n");
	for(i = 1; i <= a[0]; i++)
	{
		printf("%3d",a[i]);
	}
}

void InsertList(int a[],int x)
{
	int i;
	for( i = a[0] + 1; i > 1 && x <= a[i - 1]; i--)
	{
		a[i] = a[i - 1];
	}
	a[i] = x;
	a[0]++;


}
int main()
{
	int a[MAX];
	int x;
	Create_List(a,10);
	Print(a);
	
	printf("\n输入要插入的数 x = ");
	scanf("%d",&x);
	InsertList(a,x);
	Print(a);

	printf("\n");

	return 0;


}
