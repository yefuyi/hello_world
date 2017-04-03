/*
the function of this code:
	1.create a circulate list  whihout head and head pointer
	2.print the list
	3.delete the prior node of one node
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct	LNode//链表定义
{
	int data;
	struct LNode *next;
}LNode, *LinkList, Ll;
void CreateList(LNode *p,int n)		//create circulate list without head node and pointer
{
	int i;
	LNode *q = p;
	printf("输入%d个链表元素：\n",n);
	for(i = 1; i <= n; i++)
		{
			if(i != 1)
			{
				q -> next = (LNode *)malloc(sizeof(LNode));
				q = q -> next;
			}
			printf("输入第%d个元素：",i);
			scanf("%d",&q -> data);
		}
	q -> next = p;
}
void PrintList(LNode *p)		//print the circulate list
{
	LNode *q = p;
	while(q -> next != p){
		printf("%3d",q ->data);
		q = q -> next;
	}
	printf("%3d",q ->data);
	printf("\n");
}
void DetetePriorNode(Ll *a)		//delete the prior node of node a
{
	Ll *p = a;
	Ll *q = a -> next;
	while(p -> next ->next != a)
	{
		p = p -> next;
		q = q -> next;
	}
	p -> next = p -> next -> next;
	free(q);

}
int main()
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	LNode *q;
	int n;
	printf("input the length of the list : ");
	scanf("%d",&n);

	CreateList(p,n);
	PrintList(p);

	DetetePriorNode(p);
	PrintList(p);
	
	q = p -> next;
	DetetePriorNode(q);
	PrintList(q);
	
	return 0;
}
