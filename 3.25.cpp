/*
代码功能：
    1、函数递归的实现---->
           | n + 1          n = 0
    F(n) = |
           | n * F(n / 2)   m > 0
2017/4/7 编辑--yeqinlao            
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
    using namespace std;

int Function_F(int n)       //函数体的实现
{
    if (n < 0) exit(1);
    else if(n == 0)
        return n + 1;   //迭代停止出口
    else
    {
        return n * Function_F(n / 2);
    }
}
int main(void)  //桩测试程序
{
    int i;
    cout << "输入F()的变量n = ";
    cin >> i;
    cout << "F(" << i << ") = " <<  Function_F(i) << endl;

    return 0;
}
