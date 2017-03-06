/*
本代码实现的功能:
	1、随机数初始化表
	2、打印表
	3、计算表中元素出现概率

	4、目的产生50个0~20内的随机数，统计每个数据出现概率
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50

Create_List(int a[],int n)
{
	int i;
	for(i = 1; i <= n ;i++)
	{
		a[i] = rand()%20;
	}
	a[0] = n;
}

void Count_List(int a[],int num[])
{
	int i;
	for( i = 1; i<=a[0]; i++)
	{
		num[a[i]]++;
	}
}
void Print_List(int a[])
{
	int i;
	printf("\n");
	for(i = 1; i <= a[0]; i++)
	{
		printf("%3d",a[i]);
	}
}

int main()
{

	int a[MAX + 1];
	int i;
	int num[20] = {0};
	srand(time(0));
	Create_List(a,MAX);
	Print_List(a);

	Count_List(a,num);
	printf("\n");
	for(i = 0; i < 20; i++)
	{
		printf("%2d 出现的次数为: %d ,概率为: %.3f%% \n",i,num[i],(float)(num[i]*1.0/MAX));

	}

	return 0;



}
