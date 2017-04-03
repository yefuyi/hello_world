/*
本代码的功能：
    1、表达式中包含()、[]、{},判断括号是否匹配
2017/4/3 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack
{
    char ch[MAX];
    int top;
}Stack;

void InitStack(Stack *a)    //初始化栈
{
    a -> top = -1;  //初始时栈顶位置
}
 void Push(Stack *a, char x)    //进栈操作
 {
     if(a -> top < MAX)
     a -> ch[++ a -> top] = x;
     else exit(1);
 }
 
 char Pop(Stack *a) //出栈操作
 {
     char x;
     if(a -> top > -1)
     x = a -> ch[a -> top--];
     else exit(1);
     return x;
 }

char GetTop(Stack *a)       //返回栈顶元素
{
	char x;
    x = a -> ch[a -> top];
    return x;
}

 void GetExpression(char a[])   //表达式的录入
 {
     printf("输入表达式(@ ---->截止): \n");
	 scanf("%s",a);
 }

void JudgeBracketMatching(char a[]) //判断括号是否匹配
{
     char x;
     int i;

     Stack *s1 = (Stack *)malloc(sizeof(Stack));
     InitStack(s1);
     i = 0;
     
     while(a[i] != '@')
     {
         x = a[i];
         switch(x)
         {
            case '(':
                Push(s1,x);
                break;
            case ')':
                if(GetTop(s1) == '(')
                Pop(s1);
                else
                {
                    printf("括号不匹配!\n");
                    return;
                }
                break;
            case '[':
                Push(s1,x);
                break;
            case ']':
                if(GetTop(s1) == '[')
                Pop(s1);
                else{
                    printf("括号不匹配!\n");
                    return;
                }
                break;
            case '{':
                Push(s1,x);
                break;
            case '}':
                if(GetTop(s1) == '{')
                Pop(s1);
                else 
                {
                    return;
                }
                break;
                default:
                break;
         }
         i++;
     }
     if(s1 -> top != -1)
     {
		 printf("括号不匹配!\n");
		 return;
	 }
	 else
	 {
		 printf("括号匹配!\n");
	 }

}
int main()
 {
     char a[MAX];

     GetExpression(a);
     
     JudgeBracketMatching(a);

     
     return 0;
 }
