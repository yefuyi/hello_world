/*
代码功能:
    1、统计串中每个字符的个数，极其字符总数
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

int Index(String s,char e,int pos)   //从s中pos下标开始查找,返回第一个e的下标,不存在返回0
{
    int i,len;
    len = StrLength(s);
    for(i = pos;i < len;i++)
        if(s.ch[i] == e)
            return i;
    return -1;
}

void CountChar(String s)
//统计每一个字符的个数
{
    int i,j,len;
    len = StrLength(s);
    int counter = 0;
    int charNumber = 0;
    for(i = 0; i < len; i++)
    {
        if(Index(s,s.ch[i],0) == i)
        {   charNumber++;
			for(j = i;j < len;j++)
				if(s.ch[i] == s.ch[j])counter++;
			cout << s.ch[i] << "出现次数: " << counter << endl;
			counter = 0;
		}
		else {
			continue;	
			}
		
	
    }
    cout << "字符总数: " << charNumber << endl;
}

int main()
{
    String s;
    char s1[MAX];

    cout << "s1: ";
    cin >> s1;
	
	StrAssign(s,s1);
    CountChar(s);

    return 0;
}
