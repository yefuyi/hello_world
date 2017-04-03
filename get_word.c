/*
本代码的功能:
    1、读取流
    2、输出流中的单词
2017/3/26 编辑--yeqinlao
    
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int get_word(char *buf,int buf_size, FILE *fp)
{
    int len;
    int ch;
	//跳过读取空白字符
    while((ch = getc(fp)) != EOF && !isalnum(ch))
        ;
    if(ch == EOF)
        return EOF;
    //此时,ch中保存了单词的初始字符
    
    len = 0;
    do
    {
        buf[len] = ch;
        len++;
        if(len >= buf_size){
            fprintf(stderr,"word too long .\n");
            exit(1);
        }
    }while((ch = getc(fp)) != EOF && isalnum(ch));
    buf[len] = '\0';
    return len;
}

int main(void)
{
    char buf[256];
    while(get_word(buf, 256 , stdin) != EOF){//stdin -->从标准输入控制台中读取字符
        printf("<<%s>>\n",buf);
    }

    return 0;

}
