/*
代码功能:
	1、串的插入操作StrInsert()
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

void StrInsert(String &s, String t,int pos)		//串的插入
{
	int i = 0,j = 0;
	for(i = s.length + t.length - 1,j = s.length - 1; j >= pos; i--,j-- )
		s.ch[i] = s.ch[j];
		s.ch[s.length + t.length] = '\0';
	for(i = pos,j = 0; i < t.length + pos; i++,j++)
	{
		s.ch[i] = t.ch[j];
	}
	s.length += t.length;
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
	StrInsert(s,t,3);

	cout << "s: " << s.ch << endl;

	return 0;

}
