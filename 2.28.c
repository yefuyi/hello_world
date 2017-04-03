/*
the function of the code:
	1.create a linked list
	2.sort the list with a increasing way
	3.union a,b to a new list with a increasing way
	4.delete the same element and leave noly one 
	5.search element in the linked list
2017/3/22 code by yeqinlao
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

void  UnionA_B2A(Ll *a, Ll *b,Ll *c)		//union  linked list a , b to cwhth decreasing squence
{
	Ll *la = a -> next;
	Ll  *lb = b -> next;
	Ll *lc = c;

	while( la != NULL && lb != NULL)
	{
		if(la -> data < lb -> data)
		{
			lc -> next = la;
			la = la -> next;
			lc = lc -> next;
		}
		else
		{
			lc -> next = lb;
			lb = lb -> next;
			lc = lc -> next;
		}
	}

	if(la != NULL) lc -> next = la;	//union the remian of the a or b
	if(lb != NULL) lc -> next = lb;

	c-> data = a -> data + b -> data;
}
int SearchElem(Ll *a, int x)	//whether does the remained list have  same element with the node
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
void DeleteSameElem(Ll *a)	//delete the same element and leave only one 
{
	Ll *p = a -> next;
	Ll *q = a;
	while(p != NULL)
	{
		if(SearchElem(p, p -> data) == 1)
		{
			q -> next = p -> next;
			free(p);
			p = q -> next;
			a -> data--;
		}
		else
		{
			p = p -> next;
			q = q -> next;
		}
	}
	SortList(a);		//sort the new list again to get increasing list
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

	PrintList(a);
	PrintList(b);

	UnionA_B2A(a,b,c);

	PrintList(c);

	DeleteSameElem(c);
	PrintList(c);
	
	return 0;
}
