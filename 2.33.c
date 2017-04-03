/*
the function of this code:
	1.create a circulate linkded list
	2.print the list
	3.devide the list according to character range to three parts witch is  circulate list
2017/3/23 coding by yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	char data;
	struct LNode *next; 
}Ll,LNode;


void CreateDoubleCircluteList(Ll *a,int n)	//create a double circulate list with n node
{
	Ll *p = a;
	Ll *q;
	int i;
	a -> data = 0;
	getchar();
	for(i = 1; i <= n; i++)
	{
		q = (Ll *)malloc(sizeof(Ll));

		printf("input the %d node : ",i);
		scanf("%c",&q -> data);
		getchar();
		p -> next = q;
		p = p -> next;
		a -> data++;
	}
	p -> next = a;
}

void PrintList(Ll *a)	//print the list
{
	int i;
	Ll *p;
	if(a -> data == 0)
	{
		printf("空表！！\n");
		return;
	}
	p = a -> next;
	printf("print the in order : \n");
	for(i = 1; i <= a -> data; i++)
	{

		printf("%c", p -> data);
		p = p -> next;
	}
	printf("\n");
/*	p = p -> prior;
	printf("print the list in reverse order: \n");
	for(i = 1; i <= a -> data ; i++)
	{
		printf("%3d",p -> data);
		p = p -> prior;
	}
	printf("\n");
*/
}
void DevideThreeParts(Ll *a, Ll *b, Ll *c, Ll *d)	//devide the list depending range of character
{
	Ll *la = a -> next;
	Ll *lb = b;
	Ll *lc = c;
	Ll *ld = d;
	b -> data = 0;
	c -> data = 0;
	d -> data = 0;
	while(la != a)
	{
		if( ( la -> data >= 'a' && la -> data <= 'z') || (la -> data >='A' && la -> data <= 'Z'))
		{
			lb -> next = (Ll *)malloc(sizeof(Ll));
			lb -> next ->data= la -> data;
			la = la -> next;
			lb = lb -> next;
			b -> data++;
		}
		else if(la -> data >'0' && la -> data < '9')
		{
			lc -> next = (Ll *)malloc(sizeof(Ll));
			lc -> next -> data = la -> data;
			la = la -> next;
			lc = lc -> next;
			c -> data++;
		}
		else
		{
			ld -> next = (Ll *)malloc(sizeof(Ll));
			ld -> next -> data = la -> data;
			la = la -> next;
			ld = ld -> next;
			d -> data++;
		}
		lb -> next = b;
		lc -> next = c;
		ld -> next = d;
	}
}
int main()

{
	int i;
	Ll *a = (Ll *)malloc(sizeof(Ll));
	Ll *b = (Ll *)malloc(sizeof(Ll));
	Ll *c = (Ll *)malloc(sizeof(Ll));
	Ll *d = (Ll *)malloc(sizeof(Ll));

	printf("input the length of the list: ");
	scanf("%d",&i);

	CreateDoubleCircluteList(a,i);
	
	PrintList(a);

	DevideThreeParts(a,b,c,d);

	PrintList(b);
	PrintList(c);
	PrintList(d);

	return 0;


}
