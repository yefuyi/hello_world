#include<stdio.h>
#include<stdlib.h>
/*尾插法建立双向链表,并且打印单链表*/
/* 随机数初始化*/

#define MAX 100
#define FLASE 0
#define TRUE 1

typedef struct LNode{	//结点的定义
	int data;
	struct LNode *next;
	struct LNode *front;
}Ll,LNode;

Ll * CreateLinklist(Ll *p,int n){
	int i;
	Ll *q;
	p = (Ll *)malloc(sizeof(LNode));
	p -> next = NULL;
	q = p;
	for(i = 1; i <= n; i++){
		q -> next = (Ll *)malloc(sizeof(LNode));
		q -> next -> front = q;
		q = q -> next;
		printf("input the data of node: ");
		scanf("%d",&q->data);
	}
	q -> next = NULL;
	return p;
}
void PrintLinklist(Ll *p){
		Ll *q = p -> next;
		if(q == NULL)
		printf("Elempty List \n");
		else while(q != NULL){
				printf("%3d",q -> data);
				q = q -> next;
			}
			printf("\n");
	}
int main()
{
	Ll *p;
	p = CreateLinklist(p,10);
	PrintLinklist(p);
	return 0;
	

}
