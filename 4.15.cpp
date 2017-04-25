/*
代码功能:
    1、实现串的基本操作StrAssign(&T,chars)
2017/4/10 编辑--yeqinlao
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
	using namespace std;
#define MAX 100
typedef struct 
{
    char *ch;
    int length;
}HString;
void StrAssign(HString &s,char t[])   //生成一个值与t相等的串
{
    int i = 0;
    s.length = strlen(t);
    s.ch = new char[s.length];

    while(t[i] != '\0')
        s.ch[i] = t[i++];
    s.ch[i] = '\0';
}

int main()
{
    HString s;
    char ch[MAX];

    cout << "chars: ";
    cin >> ch;

    StrAssign(s,ch);

    cout << "S: "<< s.ch << endl;
    return 0;
}
