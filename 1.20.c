#include<stdio.h>
#define MAX 100
//一元多项式
float ploy(int i, float x) 	//x 未知数, i 阶数
{
	if( i == 0)	return 1;
	else return x * ploy(i - 1 , x);
} 
int main()
{
	int n,i;
	float a[MAX],sum,x;
	sum = 0;
	printf("输入函数的阶数 n = ");
	scanf("%d",&n);
	printf("按照项数从小到大输入系数: ");
	for( i = 0; i <= n; i++)
	scanf("%f",&a[i]) ;
	printf("输入x = ");
	scanf("%f",&x);
	for(i = 0; i <= n; i++)
	sum += a[i]*ploy(i,x);
	printf("多项式的值 = %f\n",sum);
	
	return 0;
	
}
