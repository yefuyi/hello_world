/*
代码功能:
    1、和4.11相同的功能
2017/4/20 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
	using namespace std;
#define MAX 100
typedef struct
{
	char *ch;
	int length;
}String;

void StrAssign(String &s,char chars[])
{
	s.length = strlen(chars);
    s.ch = new char[s.length];
	int i = -1;
    while(chars[++i] != '\0')
        {
			s.ch[i] = chars[i];}
    s.ch[i] = '\0';
}

int StrLength(String s)	//求串长
{

	return s.length;
}

int Index(String s,int e,int pos)   //从s中pos下标开始查找,返回第一个e的下标,不存在返回0
{
    int i,len;
    len = StrLength(s);
    for(i = pos;i < len;i++)
        if(s.ch[i] == e)
            return i;
    return -1;
}
int Index(String s,char e,int pos)   //从s中pos下标开始查找,返回第一个e的下标,不存在返回0
{
    int i,len;
    len = StrLength(s);
    for(i = pos;i < len;i++)
        if(s.ch[i] == e)
            return i;
    return -1;
}

void ConnectNext(String s,String t,String r)	//将在s中不在t中的字符添加成新串,重复字符不做操作
{
	int len_s, len_t;
	int i,j,k;
	char e1,e2;
	len_s = StrLength(s);
	len_t = StrLength(t);
	k = 0;
	for(i = 0; i < len_s;i++)
	{
		e1 = s.ch[i];
		for(j = 0; j < len_t; j++)
		{
			e2 = t.ch[j];
			if(e2 == e1)break;
		}
		if(j >= len_t)
		{
			if(Index(s,e1,0) == i)
			{
				r.ch[k++] = e1;
			}
		}
	}
	r.ch[k] = '\0';
}
int main()
{
	String s,t,r;
	char s1[MAX],t1[MAX];

	cout << "input s: ";
	cin >> s1;

	cout << "input t: ";
	cin >> t1;

	StrAssign(s,s1);
	StrAssign(t,t1);
	StrAssign(r,s1);
	ConnectNext(s,t,r);

	cout << "r: " << r.ch << endl;

	return 0;

}
