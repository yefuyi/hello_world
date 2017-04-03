/*
代码功能:
	n阶Hanoi塔问题
2017/3/15 yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
void move(char x, int n, char z)
{
	printf("%d  ----> %c ---> %c",n,x,z);
	printf("\n");
}
void hanoi(int n, char x, char y ,char z)
	/*
		将塔座x上按照直径由小到大且自上而下编号为1 ～ n的n个圆盘按照规则
		搬到塔z上y可以做辅塔。搬动操作move（x,n,z）
	*/
{
	if( n == 1) 
		move(x,1,z);	//将编号为1的圆盘从x搬到z
	else{
		hanoi(n-1,x,z,y);	//将x编号为1至n -  1的圆盘移到y,z做辅塔
		move(x,n,z);		//将x编号为n的圆盘从x移到z
		hanoi(n - 1,y,x,z);	//将y编号为1至n - 1的圆盘移到z,x做辅塔
	}
}
int main()
{
	int i;
	printf("输入汉诺塔的阶数: ");
	scanf("%d",&i);
	
	printf("需要移动的步骤： \n");
	hanoi(i,'x','y','z');
	
	return 0;
}



