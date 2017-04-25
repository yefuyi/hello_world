/*
代码功能:
	1、实现StrAssign()、StrCpy()、StrCompare()、StrLength()、Concat()、SubString().
2017/4/25  编辑--yeqinlao
 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
#define MAX 100
typedef unsigned SString[MAX + 1];	//0号单元存放串的长度

void InitString(SString &a)	//初始化
{
	unsigned t;
	int j = 1;
	a[0] = 0;
	cout << "input 0 to stop: ";
	cin >> t;
    while(t != 0)
	{
		a[j++] = t;
		a[0]++;
		cout << "input 0 to stop: ";
		cin >> t;
	}

}

void StrAssign(SString &s, unsigned char t[])	//将t初始化s
{
	int i = 0;
	s[0] = 0;
	while(t[i] != '\0')
	{
		s[i + 1] = t[i];
		s[0]++;
		i++;
	}
}

void StrCpy(SString &s, SString t)		//将t复制到s中
{
	int i = 1;
	while(i <= t[0])
	{
		s[i] = t[i];
		i++;
	}
	s[0] = t[0];
}

int StrCompare(SString s, SString t)
/*
若
	s > t返回>0
	s < t返回<0
	s = t返回0

 */
{
	int i;
	for(i = 1; i <= s[0] && i < t[0]; i++)
	{
		if(s[i] != t[i])
			return s[i] - t[i];
	}
	return s[0] - t[0];
}

int StrLength(SString s)	//长度
{
	return s[0];
}
void SubString(SString &Sub,SString s, int pos, int len)	//求s中从pos开始长为len的子串
{
	if(pos < 1 || pos > s[0]) exit(0);
	int i = 1;
	for(i = 1; i <= len ; i++)
	{
		Sub[i] = s[pos + i - 1];
	}
	Sub[0] = len;
}
void Concat(SString &T,SString S1,SString S2)	//用T返回S1和S2串接连成的新串。
{
	if(S1[0] + S2[0] <= MAX){
		int i = 0;
		for(i = 1; i <= S1[0];i++)
		{
			T[i] = S1[i];
		}
		for(i = 1; i <= S2[0]; i++)
		{
			T[S1[0] + i] = S2[i];
		}
		T[0] = S1[0] + S2[0];
	}
}
int index(SString s,SString t,int pos)		//找到s中从pos开始子串t首次出现的位置
{
	int i,j;
	for(i = pos; i <= s[0] - t[0] + 1;i++)
	{
		for(j = 1; j <= t[0]; j++)
		{
			if(s[i + j - 1] != t[j])	break;
		}
		if(j > t[0]) return i;
	}
	return 0;
}

void indexAll(SString s,SString t,int dex[])	//返回所有s中子串的位置，存放到数组dex中
{
	int i,j = 1;
	dex[0] = 0;
	for(i = 1; i <= s[0] - t[0] + 1;)
	{
		if(index(s,t,i) != 0)
		{
			dex[0]++;
			dex[j] = index(s,t,i);
			i = dex[j] + t[0];
			j++;
		}
		else break;
	}
}
int IsFound(int i, int dex[])   //是否在含有头结点的数组
{
    int j = 1;
    for(j = 1; j <= dex[0]; j++)
        if(i == dex[j])
        return i;
    return 0;
}
void DeleteString(SString &s,SString t) //删除s中含有t的子串
{
    SString temp;
    temp[0] = 0;
    int dex[MAX];
    indexAll(s,t,dex);

    for(int i = 1,j = 1; i < s[0];)
    {
        if(IsFound(i,dex) == i)
            i = IsFound(i,dex) + t[0];
        else
        {
        	temp[j++] = s[i++];
        	temp[0]++;
        }

    }
    for(int j = 1; j <= temp[0]; j++)
    {
        s[j] = temp[j];
    }
    s[0] = temp[0];

}
int main()
{
	SString a,b;
	int dex[10],i = 1;
	InitString(a);
	InitString(b);
	indexAll(a,b,dex);
    DeleteString(a,b);

	while(i <= a[0])
	cout << a[i++] << " ";
	cout << endl;
	return 0;
}
