/*
代码功能:
    1、求解平方根迭代函数
                    | p                     |p^2 - A| < e
    sqrt(A,p,e) =   |
                    | sqrt(A,(p + A/p),e,e) |p^2 - A| >=e
2017/4/7 编辑--yeqinlao                    
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
    using namespace std;

float Function_sqrt(float A,float p,float e)  //函数体的实现部分
{
    if(A < 0) exit(1);
    else if((p * p - A - e ) < 0 && (e + p * p - A) > 0 )
        return p;
    else return (Function_sqrt(A, (p + A/p)/2,e));
}

int main(void)  //桩函数测试部分
{
    float A,p,e;
    cout << "输入A,p,e = ";
    cin >> A >> p >> e;
    cout << "sqrt(" << A << ") = " << Function_sqrt(A,p,e) << endl;

    return 0;
}
