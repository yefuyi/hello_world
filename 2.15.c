#include<stdio.h>
#include<stdlib.h>
/* β�巨����������,���Ҵ�ӡ������*/

#define MAX 100
#define FLASE 0
#define TRUE 1

typedef struct LNode{	//���Ķ���
	int data;
	struct LNode *next;
}Ll,LNode;

Ll * CreateLinklist(Ll *p,int n){
	int i;
	Ll *q;
	p = (Ll *)malloc(sizeof(LNode));
	p -> next = NULL;
	p -> data = 0; 
	q = p;
	printf("¼�����ֵ: \n");
	for(i = 1; i <= n; i++){
		q -> next = (Ll *)malloc(sizeof(LNode));
		q = q -> next;
		printf("input the data of node: ");
		scanf("%d",&q->data);
		q -> next = NULL;
		p -> data ++;
	}
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
int LengthList(Ll *p)	//������ĳ��� 
{
/*	Ll *q;	//����һ 
	int i = 0;
	for( q = p -> next ; q != NULL ; q = q -> next)
	i++;
	return i;
*/
	return p -> data; //���ȴ洢��ͷ����� 
}
void ConnectList(Ll *a , Ll *b , Ll *c) 	//������ͷ����a,b����c 
{
	c -> next = a -> next;
	int i;
	Ll *p = c->next;
	for(i = 1; i < a -> data; i++) p = p -> next;
	p -> next = b -> next;
	c -> data = a -> data + b -> data; 
	
}
int main()
{
	Ll *a;
	a = CreateLinklist(a,2);
	Ll *b;
	b = CreateLinklist(b,3);
	Ll *c = (Ll *)malloc(sizeof(LNode));
	ConnectList(a,b,c);
	PrintLinklist(c);
	return 0;
	

}


