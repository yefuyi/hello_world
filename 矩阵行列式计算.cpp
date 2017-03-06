#include<stdio.h>
#include<stdio.h>
#include<iostream>
	using namespace std;
#define MAX 10
int Fun(int n, int a[MAX][MAX] );            /*函数声明*/
int main()
{
    int n = 0;                           /*初始化阶数n*/
    int i = 0, j = 0;                    /*i,j分别表示行与列*/
    int a[MAX][MAX] = {{0}};             /*定义行列式*/

	cout << "输入阶数　n = ";
    scanf("%d",&n);                      /*读入阶数*/
    while( n != 0)                       /*输入为0时退出程序*/
    {
        for( i = 0; i < n; i++)          /*此处2次循环将行列式存入数组中*/
        {
			cout << "输入第" << i + 1 << "行元素: ";
            for( j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        }
        printf("%d\n", Fun( n, a ) );
        cout << "输入非零数继续计算 : ";
        scanf("%d", &n);
    }

    return 0;
}

/*以下为计算行列式值的递归函数*/
int Fun( int n, int a[MAX][MAX] )
{
    int b[MAX][MAX] = {{0}};            /*定义数组b并初始化*/
    int i = 0, j = 0, sum = 0;          /*i，j为行与列，sum为行列式的值*/
    int x = 0,c = 0,p=0;                /*用x判断加与减，c,p为中间变量*/

    if(n == 1)
    return a[0][0];

    for(i = 0;i < n; i++)               /*此处大循环实现将余子式存入数组b中*/
    {
        for(c = 0;c < n-1; c++)
        {
            for(j = 0;j < n-1;j++)
            {
                if (c < i){             /*借助c判断每行的移动方法*/
                    p = 0;              /*当p=0时，行列式只向左移，即消去对应的第一列的数*/
                }
                else{                   /*否则行列式左移后再上移*/
                    p = 1;
                }
            b[c][j] = a[c+p][j+1];
            }
        }

        if(i % 2 == 0){                  /*i+j（此时j=0，故只考虑i）为偶数，加法预算*/
            x = 1;
        }
        else{                           /*i+j为奇数，减法运算*/
            x = (-1);
        }
     sum += a[i][0] * Fun(n - 1, b ) * x;         /*计算行列式的值*/
    }

    return sum;                                   /*将值返回*/
}
