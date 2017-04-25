/*
代码功能:
	1、删除串s中所有和串t相同的子串
2017/4/24 编辑--yeqinlao
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
void DeleteString(SString &s,SString t)
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
