/*
the function of the code:
	1.create a sequence list
	2.print the list
	3.union increaseing list a and b to a new list called c with increasing way
	4.delete the same number and leave only one 
	5.search element in the list
2017/3/22 code by yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
void CreateList(int a[],int n)	//create a sequence list with a head node
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("input the %d nomber ",i );
		scanf("%d",&a[i]);
	}
	a[0] = n;
}

void PrintList(int a[])		//print the list
{
	int i;
	if(a[0] == 0) return;
	for(i = 1; i <= a[0]; i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}
void SortList(int a[])	//using bubble method to sort the list with increasing way 
{
	int i;
	int t;
	int j;
	for( i = 1; i <= a[0]; i++)
	{
		for(j = a[0] - 1; j >= i; j--)
		{
			if(a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void UnionA_B2C(int a[], int b[],int c[])	//union a and b to c with increasing way
{
	int i,j,k;
	i = j = k = 1;
	while(i <= a[0] && j <= b[0])
	{
		if(a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while(i <= a[0]) c[k++] = a[i++];
	while(j <= b[0]) c[k++] = b[j++];

	c[0] = a[0] + b[0];
}
int SearchElem(int a[],int n)		//Search element in the list 
{
	int i;
	for(i = 1; i <= a[0]; i++)
	{
		if(a[i] == n)
			return 1;
	}
	return 0;
}
void DeleteSameElem(int a[])		//delete repeated elements and just leave one 
{
	int i;
	int j;
	int k;
	for(i = 1; i <= a[0]; i++)
	{
		for(j = i + 1; j <= a[0]; j++)
		{
			if(a[i] == a[j])
			{
				for(k = j; k <= a[0] - 1; k++)
					a[k] = a[k + 1];
				a[0]--;
			}
		}

	}
}
int main()
{
	int a[MAX],b[MAX],c[MAX];

	int n;

	printf("input the length of the list : ");
	scanf("%d",&n);
	CreateList(a,n);

	printf("input the length of the list : ");
	scanf("%d",&n);
	CreateList(b,n);

	SortList(a);
	SortList(b);

	PrintList(a);
	PrintList(b);

	UnionA_B2C(a,b,c);

	PrintList(c);

	DeleteSameElem(c);

	PrintList(c);

}





