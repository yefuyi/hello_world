/*
代码功能:
	1、实现串的基本操作Concat()
2017/4/25 编辑--yeqinlao
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

int StrCompare(String s,String t)
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

void Concat(String &T,String S1,String S2)	//串连接
{

	int i = 0;
	int j = 0;
	while(S1.ch[i] != '\0')
	{
		T.ch[i] = S1.ch[i];
		i++;
	}
	while(S2.ch[j] != '\0')
	{
		T.ch[i++] = S2.ch[j++];
	}
	T.ch[i] = '\0';
	T.length = S1.length + S2.length;
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
	Concat(r,s,t);

	cout << "r: " << r.ch << endl;

	return 0;
}
