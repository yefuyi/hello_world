#include<stdio.h>
int Fabo(int k, int m)
{
	int i,sum;
	sum = 0;
	if(m <= k - 2)return 0;
	else if(m == k - 1) return 1;
	else for(i = 1; i <= k; i++)
	{
		sum += Fabo(k,m - i);
	}
	return sum;
}
int main()
{
	int k,m,sum;
	printf("输入斐波那契数列的阶数和项数: ");
	scanf("%d%d",&k,&m);
	sum = Fabo(k,m);
	printf("%d阶斐波那契数列第%d项的值为%d",k,m,sum);
	return 0;
	
	
}
