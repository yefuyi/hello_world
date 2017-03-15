#include<stdio.h>
#include<stdlib.h>
/*
代码功能：
	1、单向循环链表的建立
	2、链表打印
2017/3/15 yeinlao
*/
typedef struct	LNode//链表定义
{
	int data;
	struct LNode *next;
}LNode, *LinkList;
void InitList(LNode *p,int n)
{
	int i;
	LNode *q;
	q = p -> next = (LNode *)malloc(sizeof(LNode));;
	printf("输入%d个链表元素：\n",n);
	for(i = 1; i <= n; i++)
		{
			printf("输入第%d个元素：",i);
			scanf("%d",&q -> data);
			q -> next = (LNode *)malloc(sizeof(LNode));
			q = q -> next;
		}
	p -> data = n;
	q -> next = p;
}
void PrintList(LNode *p)
{
	int i;
	LNode *q = p -> next;
	if(p -> data == 0){
		printf("空表！！\n");
		return;
	}
	for( i = 1; i <= p->data ;  i++){
		printf("%3d",q ->data);
		q = q -> next;
	}
	printf("\n");
}

int main()
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	InitList(p,5);
	PrintList(p);
	
	return 0;
}


