/*
代码功能:
	1、中序遍历访问二叉树(使用栈结构)
	2、按照先序次序输入二叉树的值
2017/4/18 编辑--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;

#define MAX 100
#define OK 1
#define ERROR 0
typedef struct BiTNode//二叉树的二叉链表存储结构
{
	char data;
	struct BiTNode *lchild,*rchild;  //左右子树,左孩子,右孩子
}BiTNode, * BiTree;

typedef struct 	//栈结构定义
{
	BiTree data[MAX];
	int top;
}Stack;

void InitStack(Stack &s)	//初始化栈
{
	s.top = -1;
}

void Push(Stack &s,BiTree e)	//进栈
{
	if(s.top > MAX - 1)exit(1);
	else
	{
		s.data[++s.top] = e;
	}
}

void Pop(Stack &s,BiTree &e)	//出栈
{
	if(s.top < 0) exit(1);
	else
	{
		e = s.data[s.top--];
	}
}

int StackEmpty(Stack s)	//判断栈是否为空,,1 --> 空,0 --> 非空
{
	if(s.top == -1)return 1;
	else return 0;
}

BiTree GetTop(Stack s)	//返回栈顶元素
{
	if(s.top > 0) return s.data[s.top];
	else exit(1);
}

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
int InOrderTraverse(BiTree T)
//采用二叉链表存储结构
//中序遍历二叉树非递归算法
{
	Stack s;
	BiTree p = T;
	InitStack(s);
	while(p != NULL || !StackEmpty(s))	
	{
		if(p != NULL)	
		{
			Push(s,p);//根进栈
			p = p -> lchild;	//遍历左子树
		}
		else{
			Pop(s,p);	//跟指针退栈,访问跟结点,遍历右子树
			if(!PrintElement(p ->data)) return ERROR;
			p = p ->rchild;
		}
	}
	return OK;
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	InOrderTraverse(T);
	printf("\n");
	return 0;
}
