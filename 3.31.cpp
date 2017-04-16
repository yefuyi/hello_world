/*
代码功能:
    1、判断回文字符串(以@作为结尾标志)
2017/4/11 编辑--yeqinlao
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
    using namespace std;
typedef struct LNode
{
    char data;
    struct LNode *next;
}LNode,*LNodePtr;

typedef struct
{
    LNodePtr front;
    LNodePtr rear;
    int length;
}LinkSeQueue;

void InitSeQueue(LinkSeQueue &s)    //初始化队列
{
    s.front = s.rear = new LNode;
    s.rear -> next =NULL;
    s.length = 0;
}

void EnSeQueue(LinkSeQueue &s, char e)    //进队
{
    LNodePtr p = new LNode;
    p -> data = e;
    s.rear -> next = p;
    s.rear = p;
    s.length++;
}

void DeSeQueue(LinkSeQueue &s, char &x) //出队
{
    if(s.length == 0)
    {
        return;
    }
    x = s.front -> next -> data;
    s.front -> next = s.front -> next -> next;
    s.length--;
}


void Judge(LinkSeQueue s)
{
	char x,e;
	int a[100];
	int i = 0,j = 0;
    while(s.length > 0)
    {
    	DeSeQueue(s,x);
    	a[i++] = x;
    	
	}	
	while(j < i / 2)
	{
		if(a[j] != a[i - j - 1])
		{
			cout <<"不是回文!"  << endl;
			return; 
		}
		j++;
		
	}
	cout <<"是回文!\n" ;
}
int main(void)
{
    LinkSeQueue s;
    InitSeQueue(s);

    char x,e; 
    cout << "----> ";
    cin >> x;
    while(x != '@')
    {
        EnSeQueue(s,x);
        cin >> x;
    }    
    Judge(s);
    
    return 0;
    
    
}

