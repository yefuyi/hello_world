/*
 本代码的功能:
    1、稀疏多项式的存储
    2、稀疏多项式的计算
    3、打印稀疏多项式
2017/3/23 编辑--叶勤劳
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct LNode
{
	int coefficient;
	int index;

}Ll,LNode;


void CreateList(Ll a[],int n)	//按照指数从小到大录入多项式
{
	int i;
	a[0].index = 0;
	for(i = 1; i <= n; i++)
	{

		printf("输入第%d指数 : ",i);
		scanf("%d",& a[i].coefficient);
		printf("输入第%d系数： ",i);
                scanf("%d",&a[i].index);
		a[0].index ++;
	}

}

void PrintList(Ll a[])	//print the list
{
	int i;
	printf("打印多项式: \n");
	printf("P(x) = ");
	for(i = 1; i <=a[0].index; i++)
	{
		printf("%d*x^%d",a[i].coefficient,a[i].index);
                if(i != a[0].index)
                    printf(" + ");
	}
	printf("\n");
}
int main()
{
	int i;
	Ll a[MAX];

	printf("多项式长度 ： ");
	scanf("%d",&i);

	CreateList(a,i);

	PrintList(a);

	return 0;


}
