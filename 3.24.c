/*
代码功能：
    1、编写递归函数-----> 
            |  0             (m  = 0, n >0 0)
    g(m,n)= |
            | g(m -1,2n)     (m >0 , n >= 0)
2017/4/7 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
int Function_g(int m,int n)  //函数体
{
    if(m == 0 && n >= 0)
        return 0;   //递归截止条件
    else
    {
        return (Function_g(m - 1, 2 * n) + n);
    }
}

int main()  //主函数进行g(m,n)函数的测试
{
    printf("g (5,2) = %3d\n",Function_g(5,2));

    return 0;
}
