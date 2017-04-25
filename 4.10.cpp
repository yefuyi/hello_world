/*
���빦��:
	1���Դ�������㷨
*/

/*
���빦��:
	1���󴮳�StrLength(String s)
	2�����ƴ�StrCopy(&T,s)
	3�����ıȽϳ���StrCompare(S,T),��S = T ����0��S> T ���� 1 ���� -1
	4����T ����s1��s2�����²������µĵĴ�Concat
	5����S�д����Ӵ�T������T��S�е�pos���ַ�֮���λ�á�����Ϊ��Index(S,T,pos)
	6����Sub���ش�S�ĵ�pos���ַ���len��Ԫ�ص��Ӵ�SubString(Sub,S,pos��len)
	7���ô�v�滻S�г���������T��Ȳ��ص����Ӵ�Replace(S,T,V )
	8�����ĸ�ֵStrAssign(&T,chars)
2017/4/5 �༭--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
#define MAX 100

void StrAssign(char a[])		//���ĸ�ֵ
{
	printf("���봮: ");
	scanf("%s",a);
}

int StrLength(char a[])	//�󴮳�
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

int StrCompare(char S[], char T[])	//���ıȽϣ�������ͬ����0������S�󷵻�1��С�򷵻�-1
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

void Concat(char T[],char S1[],char S2[])	//��s1��s2���ӣ����Ƹ�T
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

void SubString(char Sub[], char S[], int pos, int len )	//��S ��posλ����len��Ԫ����ɵ��Ӵ���ֵ��T
{
	int i = 0;
	int j = 0;
	for(j = pos - 1; j < pos + len - 1 ; j++,i++ )
	{
		Sub[i] = S[j];
	}

	Sub[i] = '\0';
}
void InverseString(char s[],char t[])	//����s��t
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