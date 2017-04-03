/*
the function of this code:
	1.create a double circulate linkded list
	2.print the list
2017/3/23 coding by yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *prior;
	struct LNode *next; 
}Ll,LNode;


void CreateDoubleCircluteList(Ll *a,int n)	//create a double circulate list with n node
{
	Ll *p = a;
	Ll *q;
	int i;
	a -> data = 0;
	for(i = 1; i <= n; i++)
	{
		q = (Ll *)malloc(sizeof(Ll));

		printf("input the %d node : ",i);
		scanf("%d",& q -> data);
		p -> next = q;
		q -> prior = p;
		p = p -> next;
		a -> data ++;
	}
	p -> next = a;
	a -> prior = p;
}

void PrintList(Ll *a)	//print the list
{
	int i;
	Ll *p;
	p = a -> next;
	printf("print the in order : \n");
	for(i = 1; i <= a -> data; i++)
	{

		printf("%3d", p -> data);
		p = p -> next;
	}
	printf("\n");
	p = p -> prior;
	printf("print the list in reverse order: \n");
	for(i = 1; i <= a -> data ; i++)
	{
		printf("%3d",p -> data);
		p = p -> prior;
	}
	printf("\n");
}
int main()
{
	int i;
	Ll *a = (Ll *)malloc(sizeof(Ll));

	printf("input the length of the list: ");
	scanf("%d",&i);

	CreateDoubleCircluteList(a,i);

	PrintList(a);

	return 0;


}
