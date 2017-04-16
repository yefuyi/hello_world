/*
代码介绍:
	1、顺序存储输出受限的双端循环队列
	2、入队和出对操作
2017/4/14 编辑--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
#define MAX 100
typedef struct LNode{//结点定义
	int *base;	//动态分配存储空间
	int front;
	int rear;
}Lnode,*LnodePtr,SeQueue;

void InitQueue(SeQueue &s)	//初始化队列
{
	s.base = new int[MAX];
	s.front = s.rear = 0;
}

int QueueLength(SeQueue s)	//队列长度
{
	return (s.rear - s.front + MAX )%MAX;
}
void EnQueue(SeQueue &s, int e, int i)	//进队---> 0从队首进站,1从队尾进栈
{
	int temp;
	if(i == 1)
	{
		if((s.rear + 1)% MAX == s.front) exit(1);
		s.base[s.rear] = e;
		s.rear = (s.rear + 1)%MAX;
	}
	else if(i == 0)
	{
		temp = (s.front - 1)%MAX;
		while(temp < 0)temp += MAX;

		if(temp == s.rear) exit(1);
		s.base[temp] = e;
		s.front = temp;
	}
	else exit(1);

}

void DeQueue(SeQueue &s,int &e)	//出队列,e返回队尾值
{
	if(s.front == s.rear) exit(1);
	e = s.base[s.front];
	s.front = (s.front + 1)%MAX;
}
int main(void)
{
	SeQueue s;
	int i,e;
	InitQueue(s);
	for(i = 0;i < 10; i++)
	{
		EnQueue(s,i,1);
		EnQueue(s,i + 1,0);
	}
	for(i = 0; i < 7; i++)
	{
		DeQueue(s,e);
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
