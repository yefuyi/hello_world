/*
the function of the code:
	1.create linked list
	2.print the list
	3.delete the element of list A which is same as he element of B and C
	4.search the node in the list,if successful return 1 or return 0
2017/3/22 coding by yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode        //单链表结点的定义
{
    int data;
    struct LNode *next;
}Ll, LNode;

void CreateList(Ll *a, int n)   //带头结点的单链表的构造
{
    int i = 0;
    Ll *p = a;
    for(i = 1; i<= n; i++)
    {
        p ->next = (Ll *)malloc(sizeof(Ll));
        printf("输入第%d个结点的值: ",i);
        scanf("%d",& p -> next -> data);
        p = p -> next;
    }
    p -> next = NULL;
    a -> data = n;
}

void PrintList(Ll *a)   //打印单链表
{
    Ll *p = a -> next;
    while(p != NULL)
    {
        printf("%3d", p ->data);
        p = p -> next;
    }
    printf("\n");
    
}
int SearchElem(Ll *a, int x)	//search the node in the list
{
	Ll *q = a -> next;
	while(q != NULL)
	{
		if(q -> data == x)
			return 1;
		else q = q -> next;
	}
	return 0;
}

void SortList(Ll *a)       //链表increasing排序
{
    Ll *p = a -> next;
    Ll *q;
    int n;
    for( ; p != NULL; p = p->next)
    {
        for( q = p -> next; q != NULL; q = q -> next)
        {
            if(p -> data > q -> data)
            {
                n = p->data;
                p -> data = q -> data;
                q -> data = n;
            }
        }
    }
}

void DeleteElemSameLikeB_C(Ll *a, Ll *b, Ll *c)	//delete element in A which also belong to B and C
{
	Ll *p = a -> next;
	Ll *q = a;
	while(p != NULL)
	{
		if((SearchElem(b,p->data) == 1) && (SearchElem(c, p ->data) == 1))
		{
			q -> next = p -> next;
			free(p);
			p = p -> next;
		}
		else
		{
			p = p -> next;
			q = q -> next;
		}

	}
}
int main()
{
	Ll *a = (Ll *)malloc(sizeof(Ll));

	Ll *b = (Ll *)malloc(sizeof(Ll));

	Ll *c = (Ll *)malloc(sizeof(Ll));

	int n;

	printf("input the length of list : ");
	scanf("%d",&n);

	CreateList(a,n);
	SortList(a);
	
	printf("input the length of list : ");
	scanf("%d",&n);
	CreateList(b,n);
	SortList(b);

	printf("input the length of list : ");
	scanf("%d",&n);
	CreateList(c,n);
	SortList(c);

	PrintList(a);
	PrintList(b);
	PrintList(c);

	DeleteElemSameLikeB_C(a,b,c);
	PrintList(a);
	
	return 0;
}
