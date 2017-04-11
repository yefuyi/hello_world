/*
���빦��:
	1����ͷ�ڵ��ѭ�������ʾ����
	2��ֻ����һ��ָ���βԪ�صĽ���ָ��
	3����ʼ�������ӡ����Ӳ���
2017/4/11 �༭--yeqinlao
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
	using namespace std;
typedef struct Node		//���Ķ���
{
	int  data;
	struct Node *next;
}LNode,*LNodePtr;

typedef struct 		//����ͷβָ����
{
	LNodePtr front;
	LNodePtr rear;
}LinkLNode;

void InitSqueue(LinkLNode &s)	//��ʼ��ѭ���������
{
	s.front = s.rear = new LNode;
	if(!s.front)
	{
		exit(0);
	}
	s.front -> next = s.rear;	//ѭ������
	s.rear -> next = s.front;
}

void EnQueue(LinkLNode &s, int e)	//����e������
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

void DeQueue(LinkLNode &s,int &e)	//���Ӳ���e����ֵ
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
	//�����Ƿ�Ϊѭ��
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
