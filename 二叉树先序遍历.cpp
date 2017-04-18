/*
代码功能：
	1、先序遍历构造二叉树
	2、先序访问二叉树
2017/4/18 编辑--yeqinlao
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
	struct BiTNode *lchild,*rchild;  //左右子树 
}BiTNode, * BiTree;

int CreateBiTree(BiTree &T)	//先序遍历构造二叉树
{
	char ch;
	cout << "输入结点的值: ";
	cin >> ch;
	if(ch =='0') T = NULL;
	else 
	{
		if( !( T = (BiTNode *)malloc(sizeof(BiTNode)) ) ) return ERROR;
		T->data  = ch;
		cout << "创建左子树--->( 0 停止创建)" ;
		CreateBiTree(T->lchild);
		cout << "创建右子树--->( 0 停止创建)";
		CreateBiTree(T->rchild);
	}
	return OK;

}

int PrintElement(char e) //打印元素
	{
		cout << e << " ";
		return OK;
	}

int PreOrderTraverse(BiTree T)	//先序遍历二叉树
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