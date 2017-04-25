/*
代码功能:
	1、将在s中不包含在t中的字符构成一个新串
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

void SubString(String &Sub, String S, int pos, int len )	//子串
{
	int i = 0;
	int j = 0;
	for(j = pos - 1; j < pos + len - 1 ; j++,i++ )
	{
		Sub.ch[i] = S.ch[j];
	}

	Sub.ch[i] = '\0';
	Sub.length = len;
}


int CharIndex(String a,char e)	//返回e在串中的位置--->下标+1,不存在返回0
{
	int len,i;
	len = StrLength(a);
	for(i = 0; i < len; i++)
	{
		if(a.ch[i] == e)
			return (i + 1);	
	}
	return 0;
	
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
			if(CharIndex(s,e1) == i + 1)
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
