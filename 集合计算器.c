/* 
本代码的功能:
	1、集合的初始化
	2、集合的并
	3、集合的交
	4、集合的差
	5、集合的补集
	6、集合的环合
	7、集合的环积
	8、打印集合
	* 集合的全集定义在[0 ,50]内的整数集合
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX 100

void Create_List(int a[])		//初始化集合
{
		int i,n,t;  
        n = 0;
        i = 1;
        printf("输入 0 ～ 50 之间的集合元素（-1停止输入）： \n");
        scanf("%d",&t);
        while( t != -1 && n <= MAX){
			a[i] = t;
			n++;
			i++;
			scanf("%d",&t);
        }
       if(n <= MAX)
		a[0] = n;
		else a[0] = MAX;
}

void Print_List(int a[])	//打印集合
{
	int i;
	printf("\n");
        if(a[0] == 0)
        {
            printf("空集！\n");
            return ;
        }
        printf("[");
	for(i = 1; i <= a[0]; i++)
	{
		printf("%3d",a[i]);
	}
	printf(" ] \n");
}
void Fun1(int a[],int  b[],int c[])	//集合的并
{
	int i,j,k;
	c[0]=a[0];
	j = k = 1;
	for(i =1; i<=a[0];i++)
	{
		c[k] = a[i];
		k++;
	}
	while(j <= b[0])
	{
		for(i = 1;i <= k; i++)
		{
			if(b[j] == c[i]) break;
				
		}
		if(i >= k )
		{
			c[k] = b[j];
			j++;
			k++;
			c[0]++;
		}
		else
			j++;
	}

}

void Fun2(int a[], int b[], int c[])	//集合的交
{
		int i,j,k;
		c[0] = 0;
		k = 1;
		for(i = 1; i <= a[0] ; i++){
				for(j = 1; j <= b[0]; j++){
						if(a[i] == b[j]){
						c[k++] = a[i];
						c[0]++;
							}
					}
			}
}

void Fun3(int a[], int b[], int c[]) 	//集合的差
{
		int i,j,k;
		c[0] = 0;
		k = 1;
		for(i = 1; i <= a[0] ; i++){
				for(j = 1; j <= b[0]; j++){
						if(a[i] == b[j]) break;
					}
				if(j > b[0]) {
						c[k++] = a[i];
						c[0]++;
					}
			}
}

void Fun4(int a[], int c[])		//集合的补集
{
		int i,j,k;
		c[0] = 0;
		k = 1;
		for(i = 1; i <= 50; i++)
		{
				for(j = 1; j <= a[0]; j++){
						if(i == a[j])
						break;
					}
				if( j > a[0]){
						c[k++] = i;
						c[0]++;
					}
		}
		
}

void Fun5(int a[], int b[], int c[])		//集合的环合
{
		int e[MAX],d[MAX];
		Fun3(a,b,e);	//a - b
		Fun3(b,a,d);	//b - a
		Fun1(e,d,c);	// (a - b) 并 (b - a)
}
void Fun6(int a[], int b[] , int c[])       //集合的环积
{
		int d[MAX];
		Fun5(a,b,d);
		Fun4(d,c);
}

void Menu()
{
	int a[MAX],b[MAX],c[MAX];
    int i;
        
        printf("\n 1、集合的并\n 2、集合的交\n 3、集合的差\n 4、集合的补集\n 5、集合的环合\n 6、集合的环积\n 7、退出\n");
        printf("选择要进行的操作（1 ～ 7）");
        scanf("%d",&i);
        switch(i){
            case 1:
    printf("输入第一个集合: ");
	Create_List(a);
	printf("输入第二个集合: ");
	Create_List(b);
	Fun1(a,b,c);
        printf("\n集合的并:  ");
	Print_List(c);
        break;
        
            case 2:
    printf("输入第一个集合: ");          
	Create_List(a);
    printf("输入第二个集合: ");
	Create_List(b);
        Fun2(a,b,c);
        printf("\n集合的交:  ");
	Print_List(c);
        break;
        
            case 3:
    printf("输入第一个集合: ");          
	Create_List(a);
    printf("输入第二个集合: ");
	Create_List(b);
        Fun3(a,b,c);
        printf("\n集合的差:  ");
	Print_List(c);
        break;
        
            case 4:
    printf("输入集合元素： ");
	Create_List(a);
        Fun4(a,c);
        printf("\n集合的补集:  ");
	Print_List(c);
        break;
        
            case 5:
    printf("输入第一个集合: ");          
	Create_List(a);
    printf("输入第二个集合: ");
	Create_List(b);
        Fun5(a,b,c);
        printf("\n集合的环和:  ");
	Print_List(c);
        break;
        
            case 6:
    printf("输入第一个集合: ");          
	Create_List(a);
    printf("输入第二个集合: ");
	Create_List(b);
        Fun6(a,b,c);
        printf("\n集合的环积:  ");
	Print_List(c);
	break;
        
            default: printf("××× 退出程序 ××××\n");
        }    
    
}
int main()
{
        int i;
        i = 1;
        while(i == 1)
        {
            Menu();
            printf("输入数字1继续操作: ");
            scanf("%d",&i);
        }
        printf("\n");
        
        

	return 0;
	
}
