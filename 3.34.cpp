/*
代码功能：
	1、车厢顺序调度通过输出受限的双端队列实现
	2、'E'、'D'分别表示队列进队和出队的操作
	3、要求硬座P在前、软卧S居中、硬卧H在后
2017/4/26 编辑--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;

#define MAX 100
typedef struct LNode{//结点定义
	char data;	//动态分配存储空间
	struct LNode *next;
	struct LNode *prior;
}Lnode,*LnodePtr;

typedef struct{ //队列的定义
    int length;
    Lnode *front;
    Lnode *rear;
}SeQueue;

void InitQueue(SeQueue &s)	//初始化队列
{
	s.front = s.rear = new LNode;
	//s.front -> next  = s.rear;
	//s.rear -> prior = s.front;
	s.front -> next = NULL;
	s.front -> prior = s.rear -> next = NULL;
	s.length = 0;
}

int QueueLength(SeQueue s)	//队列长度
{
	return s.length;
}
void EnQueue(SeQueue &s, char e, int i)	//进队---> 0从队首进站,1从队尾进栈
{
	Lnode *p = new Lnode;
	p -> data = e;
	if(i == 1)
	{
		s.rear -> next = p;
		p -> prior = s.rear;
		p -> next = NULL;
		s.rear = p;
		s.length++;
	}
	else if(i == 0)
	{
	    p -> next = s.front -> next;
	    s.front -> next = p;
	    p -> prior = s.front;
	    s.length++;

	}
	else exit(1);

}

void DeQueue(SeQueue &s,char &e)	//出栈,e返回队尾值
{
    LNode *p;
	if(s.length == 0) exit(1);
	p = s.front -> next;
	e = p -> data;
	s.front -> next = p -> next;
	if(p -> next != NULL)
        p -> next -> prior = s.front;
	s.length--;
	free(p);
}
int main(void)
{
	SeQueue s;
	int i;
	char x[20],e;
	InitQueue(s);
	cout << "input: ";
	cin >> x;
	for(i = 0;i < 20; i++)
	{
		if(x[i] == '#')break;
		else if(x[i] == 'S')
			EnQueue(s,x[i],0);
		else if(x[i] == 'H')
			EnQueue(s,x[i],1);
		else cout << x[i] << " ";
	}

	while(s.front -> next != NULL)
	{
		DeQueue(s,e);
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
