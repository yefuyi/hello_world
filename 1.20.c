#include<stdio.h>
#define MAX 100
//һԪ����ʽ
float ploy(int i, float x) 	//x δ֪��, i ����
{
	if( i == 0)	return 1;
	else return x * ploy(i - 1 , x);
} 
int main()
{
	int n,i;
	float a[MAX],sum,x;
	sum = 0;
	printf("���뺯���Ľ��� n = ");
	scanf("%d",&n);
	printf("����������С��������ϵ��: ");
	for( i = 0; i <= n; i++)
	scanf("%f",&a[i]) ;
	printf("����x = ");
	scanf("%f",&x);
	for(i = 0; i <= n; i++)
	sum += a[i]*ploy(i,x);
	printf("����ʽ��ֵ = %f\n",sum);
	
	return 0;
	
}
