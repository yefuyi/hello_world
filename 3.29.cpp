/*
代码功能:
	1、循环队列中的元素都能得到利用
	2、设置一个标志域tag = 0、1区分，0 -->队列为空 1 -->队列为满
	3、编写相应入队和出队操作
2017/4/11  编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
#define MAX 10
typedef struct SeqLNode		//结点的定义
{
	int *base;
	int front;
	int rear;
	int tag;	//标志位判断空和满
}SeQueue,*SeQueuePtr;


void InitSqueue(SeQueue &s)	//初始化循环链表队列
{
	s.base = new int[MAX];
	if(!s.base)
	{
		exit(0);
	}
	s.front = s.rear = 0;	//循环链表

	s.tag = 0;//此时栈空
}

int QueueLength(SeQueue s)
{
	return (s.rear -s.front + MAX) % MAX;
}

void EnQueue(SeQueue &s, int e)	//插入e到队列
{
	if(s.tag == 1) return;
	if((s.rear + 1)% MAX == s.front)	//队列满
	{
		s.tag = 1;
	}
	s.base[s.rear] = e;
	s.rear = (s.rear + 1)%MAX;

}

void DeQueue(SeQueue &s,int &e)	//出队并用e返回值
{
	if(s.rear == s.front)
	{
		s.tag = s.tag ;
	}
	e = s.base[s.front];
	s.front = (s.front + 1)%MAX;
}

int main(void)
{
	SeQueue s;
	int e;
	InitSqueue(s);
	int i;

	for(i = 0; i < MAX; i++)
	{
		EnQueue(s,i);
	}

	for(i = 0; i < MAX; i++)
	{
		DeQueue(s,e);
		printf("%3d",e);
	}
	cout << endl;

	return 0;
}
