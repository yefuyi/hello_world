/*
本代码包含的功能:
	1、合并表A、B 到A
	2、随机数初始化表
	3、打印表
	4、合并非递减A、B到表C



*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15	//A
#define M 5		//B
#define MAX 100
void UnionToA(int a[], int b[])		//合并表A和表B到A;
{
	int i,j,k;
	i = a[0] + 1;
	for(j = 1; j <= b[0]; j++)
	{
		k = 1;
		while(b[j] != a[k] && k < i) 
			k++;
		if(k >= i )
		{
			a[i] = b[j];
			i++;
		}
	}
	a[0] = i - 1;

}

void Create_List(int a[],int n)		//创建链表
{
	int i;
	for(i = 1; i <= n; i++)
	{
		a[i] = rand()/1000;
	}
	a[0] = n;
}

void Print(int a[])		//打印链表
{
	int i;
	printf("\n");
	for(i = 1; i <= a[0]; i++)
	{
		printf("%5d",a[i]);
	}
}

void MergeList(int a[],int b[],int c[])			//表A、B元素值非递减排列。归并A、B到表C
{
	int i,j,k;
	i = j = k = 1;
	while(i <= a[0] || j <= b[0])
	{
		if(a[i] < b [j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
		k++;
	}

	while(i <= a[0])
	{
		c[k++] = a[i++];
	}
	while(j <= b[0])
	{
		c[k++] = b[j++];
	}
}

int main()
{
	int a[MAX],b[MAX];
	srand(time(0));
	Create_List(a,10);
	Create_List(b,10);
	Print(a);
	Print(b);

	UnionToA(a,b);
	Print(a);

	printf("\n");

	return 0;


}
