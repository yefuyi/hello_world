/*
代码功能:
    1、实现串的删除操作DeleteSubString(s,t,v)
2017/4/20 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
    using namespace std;
#define MAX 100

int StrLength(char a[])   //返回串的长度
{
    int i = 0;
    while(a[i] != '\0')
    {
        i++;
    }
    return i;
}

void SubString(char s[],char t[],int pos,int len)   //使用t返回串s从pos个字符起长度为len的子串
{
    if(pos < 1 || pos > StrLength(s)) exit(1);
    int i;
    for(i = 0; i < len; i++)
    {
        t[i] = s[pos  - 1 + i];
    }
    t[i] = '\0';
}

int StrCompare(char s[],char t[])
//s > t 返回>0
//s = t 返回 0
//s < t 返回 <0
{
    int i;
    for(i = 0; i < StrLength(s) && i < StrLength(t); i++)
    {
        if(s[i] != t[i])    return s[i] - t[i];
    }
    return StrLength(s) - StrLength(t);
}

int Index(char s[],char t[],int pos)
//主串s中第pos个字符之后存在与t相等的子串
//则返回第一个这样的子串在s中的位置,否则为零
{
    if(pos > 0)
    {
        int n = StrLength(s);
        int m = StrLength(t);
        int i = pos - 1;
        char sub[MAX];
        while(i < n - m + 1)
        {
            SubString(s,sub,i + 1,m);
            if(StrCompare(sub,t) != 0) i++;
            else return i;
        }
    }
    return -1;
}

void DeleteSubString(char s[],char t[])
/*
实现删除子串的操作
*/

{
    int n = StrLength(s);
    int m = StrLength(t);
    //int l = StrLength(v);
    //char temp[MAX];
	int dex[MAX],d = 0;
	char temp[MAX];
    int i,pos,j;

    for(i = 0; i < n ;i = pos + m)	//得到所有子串的位置下标
    {
        pos = Index(s,t,i + 1);
        if(pos == -1) {
			dex[d]= -1;
			break;
		}
        else
        {
            dex[d++] = pos;
        }
    }
    if(i >=n && dex[d] != -1)dex[d] = -1;	//越界检查
    j = 0;
    d = 0;
    for(i = 0; i < n;)	//将新串存储到临时数组
    {
        if(i == dex[j])
        {
			i = i + m;
			j++;
        }
        else {
			temp[d++] = s[i];
			i++;
		}
		
        
    }
   temp[d] = '\0';
   j = 0;
   while(temp[j] != '\0')
	s[j] = temp[j++];
	s[j] = '\0';
    
 
}

int main()
{
    char a[MAX],b[MAX];
    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;
    
   // cout << "index : " << Index(a,b,1) << endl;
	DeleteSubString(a,b);
	cout << "a: " << a << endl;
    return 0;
}

