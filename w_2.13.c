#include<stdio.h>
#include<stdlib.h>
/* ���빦��:
1��β�巨����������
2����ӡ������
3������Ԫ��λ�� 
*/

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
	q = p;
	for(i = 1; i <= n; i++){
		q -> next = (Ll *)malloc(sizeof(LNode));
		q = q -> next;
		printf("input the data of node: ");
		scanf("%d",&q->data);
		q -> next = NULL;
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
int Locate (Ll *p,int e)
{
	Ll *q;
	int i;
	i = 1;
	for(q = p->next; q != NULL ; q = q->next)
	{
		if(q->data == e) break;
		else i++;
	}
	if( q == NULL) return 0;
	else return i;
}
int main()
{
	Ll *p;
	p = CreateLinklist(p,5);
	PrintLinklist(p);
	int e;
	printf("����Ҫ���ҵ�Ԫ�� e = ") ;
	scanf("%d",&e);
	int i = Locate(p,e);
	if(i == 0) printf("�����ڸ�Ԫ��!!\n") ;
	else printf("��Ԫ�ص�λ�������Ա��%d����\n",i);
	return 0;
	

}

