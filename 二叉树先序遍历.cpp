/*
���빦�ܣ�
	1������������������
	2��������ʶ�����
2017/4/18 �༭--yeqinlao
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
	using namespace std;
#define OK 1
#define ERROR 0
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;  //�������� 
}BiTNode, * BiTree;

int CreateBiTree(BiTree &T)	//����������������
{
	char ch;
	cout << "�������ֵ: ";
	cin >> ch;
	if(ch =='0') T = NULL;
	else 
	{
		if( !( T = (BiTNode *)malloc(sizeof(BiTNode)) ) ) return ERROR;
		T->data  = ch;
		cout << "����������--->( 0 ֹͣ����)" ;
		CreateBiTree(T->lchild);
		cout << "����������--->( 0 ֹͣ����)";
		CreateBiTree(T->rchild);
	}
	return OK;

}

int PrintElement(char e) //��ӡԪ��
	{
		cout << e << " ";
		return OK;
	}

int PreOrderTraverse(BiTree T)	//�������������
{
	if(T != NULL)
	{
		if(PrintElement(T->data))
		{
			if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild)) return OK;
		}
	}
	else return OK;
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");

	return 0;
	
}