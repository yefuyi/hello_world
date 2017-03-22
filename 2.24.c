/*
本代码的功能：
    1、单链表的构造
    2、单链表的打印
    3、单链表递减排序
    4、合并a,b到a,保持递减排序
2017/3/22 编辑--yeqinlao
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

void SortList(Ll *a)       //链表递减排序
{
    Ll *p = a -> next;
    Ll *q;
    int n;
    for( ; p != NULL; p = p->next)
    {
        for( q = p -> next; q != NULL; q = q -> next)
        {
            if(p -> data < q -> data)
            {
                n = p->data;
                p -> data = q -> data;
                q -> data = n;
            }
        }
    }
}

void  UnionA_B2A(Ll *a, Ll *b)		//union  linked list a , b whth decreasing squence to a
{
	Ll *la = a -> next;
	Ll  *lb = b -> next;
	Ll *lc = a;

	while( la != NULL && lb != NULL)
	{
		if(la -> data > lb -> data)
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
}

int main()
{
	Ll *a = (Ll *)malloc(sizeof(Ll));

	Ll *b = (Ll *)malloc(sizeof(Ll));

	int n;

	printf("input the length of list : ");
	scanf("%d",&n);

	CreateList(a,n);

	printf("input the length of list : ");
	scanf("%d",&n);
	CreateList(b,n);

	PrintList(a);
	PrintList(b);

	UnionA_B2A(a,b);

	PrintList(a);

	return 0;
}



