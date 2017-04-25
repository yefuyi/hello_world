/*
代码功能:
	1、对串求逆的算法
*/

/*
代码功能:
	1、求串长StrLength(String s)
	2、复制串StrCopy(&T,s)
	3、串的比较长度StrCompare(S,T),若S = T 返回0，S> T 返回 1 否则 -1
	4、用T 返回s1和s2连接新产生的新的的串Concat
	5、若S中存在子串T，返回T在S中第pos个字符之后的位置。否则为零Index(S,T,pos)
	6、用Sub返回串S的第pos个字符起长len个元素的子串SubString(Sub,S,pos，len)
	7、用串v替换S中出现所有与T相等不重叠的子串Replace(S,T,V )
	8、串的赋值StrAssign(&T,chars)
2017/4/5 编辑--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
#define MAX 100

void StrAssign(char a[])		//串的赋值
{
	printf("输入串: ");
	scanf("%s",a);
}

int StrLength(char a[])	//求串长
{
	int  len = 0;
	int i = 0;
	while(a[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

int StrCompare(char S[], char T[])	//串的比较，长度相同返回0，否则S大返回1，小则返回-1
{
	int len_s = 0;
	int len_t = 0;

	len_s = StrLength(S);
	len_t = StrLength(T);

	if(len_s > len_t)
		return 1;
	else if(len_s < len_t)
		return -1;
	else return  0;
}

void Concat(char T[],char S1[],char S2[])	//将s1和s2连接，复制给T
{
	int len_s1 = StrLength(S1);
	int len_s2 = StrLength(S2);

	int i = 0;
	int j = 0;
	while(S1[i] != '\0')
	{
		T[i] = S1[i];
		i++;
	}
	while(S2[j] != '\0')
	{
		T[i++] = S2[j++];
	}
	T[i] = '\0';
}

void SubString(char Sub[], char S[], int pos, int len )	//将S 第pos位置起len个元素组成的子串赋值给T
{
	int i = 0;
	int j = 0;
	for(j = pos - 1; j < pos + len - 1 ; j++,i++ )
	{
		Sub[i] = S[j];
	}

	Sub[i] = '\0';
}
void InverseString(char s[],char t[])	//逆置s到t
{
	int len = StrLength(s);
	int i,j;
	for(i = 0 ,j = len - i - 1 ; i < len; i++,j--)
	{
		t[i] = s[j];	
	}
	t[i] = '\0';

}
int main(void)
{
	char ch1[MAX],ch2[MAX];

	StrAssign(ch1);
	InverseString(ch1,ch2);
	cout <<StrLength(ch1) << endl;
	cout << ch2 << endl;

	return 0;


}