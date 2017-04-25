/*
代码功能:
    1、实现串的置换操作relplace(s,t,v)
    *出现了神奇的bug
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


int Index(String s,String t,int pos)
//主串s中第pos个字符之后存在与t相等的子串
//则返回第一个这样的子串在s中的位置,否则为零
{
    if(pos > 0)
    {
        int n = StrLength(s);
        int m = StrLength(t);
        int i = pos - 1;
        String sub;
        while(i < n - m + 1)
        {
            SubString(sub,s,i + 1,m);
            if(StrCompare(sub,t) != 0) i++;
            else return i;
        }
    }
    return -1;
}

void AllIndex(String s,String t,int dex[])
{
	int n = StrLength(s);
    int m = StrLength(t);
    int i,pos,d = 0;
    cout << " " << endl;
    for(i = 0; i < n - m + 1;i = pos + m)
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
	 dex[d] = -1;
	 //int j = -1;
	 //while(dex[++j] != -1) cout << dex[j] << endl;
}
void Replace(String &s,String t,String v)
/*
实现置换操作
*/

{
    int n = StrLength(s);
    int m = StrLength(t);
    //int l = StrLength(v);
    //char temp[MAX];
	int dex[MAX],d = 0;
	char temp[MAX];
    int i,j,k;

	AllIndex(s,t,dex);
    j = 0;
    for(i = 0; i < n;)
    {
        if(i == dex[j])
        {
			k= 0;
			while(v.ch[k] != '\0')
				temp[d++] = v.ch[k++];
			i = i + m;
			j++;
        }
        else {
			temp[d++] = s.ch[i];
			i++;
		}
		
        
    }
   temp[d] = '\0';
   j = -1;
   while(temp[++j] != '\0')
	s.ch[j] = temp[j];
	s.ch[j] = '\0';
    
}

int main()
{
    char a1[MAX],b2[MAX],c3[MAX];
    String a,b,c;
    
    cout << "a: ";
    cin >> a1;

    cout << "b: ";
    cin >> b2;
    
    cout << "c: ";
    cin >> c3;
    StrAssign(a,a1);
    StrAssign(b,b2);
    StrAssign(c,c3);
   // cout << "index : " << Index(a,b,1) << endl;
	Replace(a,b,c);
	cout << "a: " << a.ch << endl;
    return 0;
}

