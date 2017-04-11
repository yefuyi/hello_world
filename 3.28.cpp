/*
代码功能:
	1、带头节点的循环链表表示队列
	2、只设置一个指向队尾元素的结点的指针
	3、初始化、出队、进队操作
2017/4/11 编辑--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
typedef struct Node		//结点的定义
{
	int  data;
	struct Node *next;
}LNode,*LNodePtr;

typedef struct 		//队列头尾指针域
{
	LNodePtr front;
	LNodePtr rear;
}LinkLNode;

void InitSqueue(LinkLNode &s)	//初始化循环链表队列
{
	s.front = s.rear = new LNode;
	if(!s.front)
	{
		exit(0);
	}
	s.front -> next = s.rear;	//循环链表
	s.rear -> next = s.front;
}

void EnQueue(LinkLNode &s, int e)	//插入e到队列
{
	LNodePtr p = new LNode;
	if(!p) 
	{
		exit(0);
	}
	p -> data = e;
	p -> next = s.front;
	s.rear -> next = p;
	s.rear = p;
}

void DeQueue(LinkLNode &s,int &e)	//出队并用e返回值
{
	if(s.front == s.rear)
	{
		exit(0);
	}
	LNodePtr p = s.front -> next;
	e = p -> data;
	s.front -> next = p -> next;
	if(s.rear == p)
		s.rear = s.front;
	free(p);
}

int main(void)
{
	LinkLNode s;
	LNodePtr p;
	int e,i;
	InitSqueue(s);
	for(i = 1; i <=6; i++)
	{
		EnQueue(s,i);
	}
	//测试是否为循环
	/*for( p = s.front -> next; p != s.front; p = p -> next)
	{
		cout << p -> data ;
	}
	*/
	cout << endl;
	for(i = 1; i <=6; i++)
	{
		DeQueue(s,e);
		printf("%3d",e);
	}


	printf("\n");

	return 0;
}
