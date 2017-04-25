/*
代码功能:
    1、实现串的基本操作Strcompare(&T,chars)
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
    
    s.length = strlen(t);
    s.ch = new char[s.length];
	int i = 0;
    while(t[i] != '\0')
        s.ch[i] = t[i++];
    s.ch[i] = '\0';
}

int StrCompare(HString s,HString t)
/*
s > t --->返回>0
s < t --->返回<0
s = 0 --->返回=0
*/
{
    for(int i = 0; i < s.length && i < t.length; i++)
    {
        if(s.ch[i] != t.ch[i])  return s.ch[i] - t.ch[i];
    }
    return s.length - t.length;
}
int main()
{
    HString s,t;
    char ch1[MAX],ch2[MAX];

    cout << "chars: ";
    cin >> ch1;

    StrAssign(s,ch1);

    cout << "chars: ";
    cin >> ch2;

    StrAssign(t,ch2);

    cout << "StrCompare(s,t) "<< StrCompare(s,t) << endl;
    return 0;
}
