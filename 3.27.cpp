/*
代码功能:
    1、Ackerman函数定义
                | n + 1                     m = 0
    akm(m,n) =  | akm(m - 1 ,1)             m != 0, n = 0
                | akm(m-1,akm(m,n - 1))     m != 0, n != 0
    2、函数的递归算法
    3、函数的非递归算法
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
    using namespace std;
#define MAX 100
typedef struct temp
{
	int mval;
	int nval;
}temp;

typedef struct Seq_Stack
{
    temp data[MAX];
    int top;
}*SeqStack;

void InitSeqStack(SeqStack s)   //顺序栈的初始化
{
    s -> top = -1;
}
void Push(SeqStack s, temp e)       //进栈
{
    if(s -> top >= MAX) exit(1);
    else s -> data[++s -> top] = e;
}
void Pop(SeqStack s,temp &e) //出栈,并返回栈顶元素的值
{
    if(s -> top < 0) exit(1);
    else
    {
        e = s -> data[s -> top--];
    }
}
int LengthSeqStack(SeqStack s)  //返回栈的长度
{
    return s -> top + 1;
}

int Recursion_Akm(int m,int n)
{
    if(m < 0 || n < 0) exit(1);
    else if(m == 0)
        return n + 1;
    else if( m != 0 && n == 0)
        return Recursion_Akm(m - 1,1);
    else 
    {
        return Recursion_Akm(m - 1,Recursion_Akm(m, n - 1));
    }
}

int NotRecursion_Akm(int m,int n)
{
    SeqStack s = new Seq_Stack;
    InitSeqStack(s);
    temp e,e1;
    e.mval = m;
    e.nval = n;
    Push(s,e);	//将m,n进栈
    do{
        while(e.mval){	//如果m大于零执行
             while(e.nval){//如果n大于零执行
                        e.nval--;	//进栈,并且n-1
                        Push(s,e);	
                    }
                e.mval--;	//m - 1, n = 1
                e.nval = 1;
            }
        if(LengthSeqStack(s)>1){	//出栈操作
            e1.nval = e.nval;	//将e中操作后的n赋值给e1
            Pop(s,e);//出栈,并且将将值给e
            e.mval--;//m - 1
            e.nval=e1.nval+1; // n = n + 1
        }
    }while(LengthSeqStack(s)!=1||e.mval!=0);
    return e.nval+1;	//最后的值赋给此处
}


int main()  //桩函数测试
{
    int m,n;
    cout << "m,n = ";
    cin >> m >> n;
    cout << "NotRecusionAkm(" << m << "," << n <<") = " << NotRecursion_Akm(m,n) << endl;
    cout << "RecusionAkm(" << m << "," << n <<") = " <<Recursion_Akm(m,n) << endl;

    return 0;
}
