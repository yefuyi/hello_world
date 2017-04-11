/*
代码的简介:
    1、表达式由单字母变量和双目四则运算符组成。
    2、将书写正确的表达式转换为逆波兰式(后序遍历)
2017/4/3 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct Stack
{
    char ch[MAX];
    int top;
}Stack;

typedef char ElemType;

void InitStack(Stack *s)    //初始化栈
{
    s -> top = -1;
}
// 输入的表达式串必须为#...#格式
void Push(Stack *s, char x) //进栈操作
{
    if(s ->top >= MAX)
    exit(1);
    else
    s -> ch[++ s -> top] = x;
}
void GetTop(Stack *s, char *e)
{
    if(s->top < 0)
    exit(1);
    else
    *e = s ->ch[s -> top];
}

void Pop(Stack *a, char *e) //出栈,并且将值付给e
{
    if(a ->top < 0)
    exit(1);
    else
    *e = a -> ch[a -> top--];
}

int StackEmpty(Stack *a)    //栈空
{
    if(a -> top == -1)
    return 1;
    else return 0;
}

int IsOpertor(char c)    //操作符判断
{
    char *p="#+-*/";
    while(*p){
        if(*p==c)
        return TRUE;
        p++;
    }
    return FALSE;
}

int Prior(char c1,char c2)
{
    char ch[]="#+-*/";
    int i=0,j=0;
    while(ch[i] && ch[i]!=c1) i++;
    if(i==2) i--;
    // 加和减可认为是同级别的运算符
    if(i==4) i--;
    // 乘和除可认为是同级别的运算符
    while(ch[j] && ch[j]!=c2) j++;
    if(j==2) j--;
    if(j==4) j--;
    if(i>=j) return TRUE;
    else return FALSE;
}
void InversePolandExpression(char Buffer[])
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    InitStack(s);
    int i=0,j=0;
    ElemType e;
    Push(s,Buffer[i]);
    i++;

    while(Buffer[i]!='#'){
		if(!IsOpertor(Buffer[i])){ // 是操作数
			Buffer[j]=Buffer[i];
			i++;
			j++;
    }
    else{
        // 是操作符
        GetTop(s,&e);
        if(Prior(e,Buffer[i])){// 当栈顶优先权高于当前序列时,退栈
            Pop(s,&e);
            Buffer[j]=e;
            j++;
        }
        else{
        Push(s,Buffer[i]);
        i++;
        }
    }
}
    while(!StackEmpty(s)){
            Pop(s,&e);
            Buffer[j]=e;
            j++;
        }
}
int main(void)
{
    char Buffer[MAX];
    
	printf("输入表达式 --->#...#形式: ");
	scanf("%s",Buffer);
    InversePolandExpression(Buffer);

    puts(Buffer);

    return 0;
    
}