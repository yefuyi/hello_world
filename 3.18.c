/*
本代码的功能:
    1、判断括号是否匹配
2017/3/29 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Stack
{
    char a[MAX];
    int top;
}Stack;

void InitStack(Stack *a)    //初始化栈
{
    a -> top = -1;
}

void Push(Stack *a, char x)     //入栈
{
    if(a -> top >= MAX)
    {
        printf("栈满!\n");
        return;
    }
    a -> a[++ a -> top] = x;
}

char Pop(Stack *a)  //出栈并返回其元素的值
{
    char x;
    if(a -> top < 0)
    {
        printf("栈空!\n");
        exit(1);
    }
    x = a -> a[a -> top--];
    return x;
}

void GetExpression(Stack *a)        //输入表达式
{
    char x;
    printf("输入表达式:\n");
    printf("输入符号：(0 ---> 截止) ");
    scanf("%c",&x);
    while(x != '0' && a -> top < MAX)
    {
        a -> a[ ++ a -> top] = x;
        getchar();
        printf("输入符号：(0 ---> 截止) ");
        scanf("%c",&x);
    }
}
void JudgeBracket(Stack *a)     //判断括号是否匹配
{
    Stack *b = (Stack *)malloc(sizeof(Stack));
    char bracket[MAX];
    int top1 = 0;
    char x;
    int i = 0;
    int j = 0;
    
    InitStack(b);
    
    while(top1 <= a -> top)
    {
        x = a -> a[top1++];
        if( x  == ')')
            Push(b,x);
        if(x == '(')
            Push(b,x);
        if(x == ']')
			Push(b,x);
		if(x == '[')
			Push(b,x);
    }
    while(b -> top > -1)
    {
        bracket[i++] = Pop(b);
    }

    for(j = 0; j <= i/2; j++)
    {
        if(bracket[j] == ')')
        {
            if(bracket[i - j - 1] != '(')
            {
                printf("括号不匹配!\n");
                return;
            }
        }
        if(bracket[j] == ']')
        {
            if(bracket[i - j - 1] != '[')
            {
                printf("括号不匹配!\n");
                return;
            }
        }
    }
    printf("括号匹配成功!\n");
    
    
    free(b);
}

int main(void)
{
    Stack *a = (Stack *)malloc(sizeof(Stack));
    InitStack(a);
    
    GetExpression(a);

    JudgeBracket(a);
    

    return 0;
}







