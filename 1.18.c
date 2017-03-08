#include<stdio.h> 
#include<string.h>
#define MAX 100
typedef struct Score	//	总成绩表 
{
	char SchoolName;
	char Gender;
	char SportName[10];
	float Score;
	int Grade;
}Sc;
typedef struct School		//各个学校成绩表 
{
	int BoyScore;
	int GirlScore;
	int SumScore;
}Dandu;
int LuRu(Sc ChengJiBiao[])	//录入成绩 
{
	int i,j;
	j = 0;
	printf("是否输入成绩：(0 --> no , 1 ---> yes): ");
	scanf("%d",&i);
	while(i != 0)
	{
		printf("输入项目名称: ");
		scanf("%s",ChengJiBiao[j].SportName);
		getchar();
		printf("输入性别(M or W): ");
		scanf("%c",&ChengJiBiao[j].Gender);
		getchar();		//吸收回车符号 
		printf("输入校名: ");
		scanf("%c",&ChengJiBiao[j].SchoolName);	
		printf("输入成绩: ");
		scanf("%f",&ChengJiBiao[j].Score);
		printf("输入得分: ");
		scanf("%d",&ChengJiBiao[j].Grade);
		j++;
		printf("是否输入成绩：(0 --> no , 1 ---> yes): ");
		scanf("%d",&i);
	}
	return j;
	
}
void ChuLi(Sc ChenJiBiao[], Dandu sch[],int n)		//成绩统计 
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		switch(ChenJiBiao[i].SchoolName)
		{
				case 'A':
				if(ChenJiBiao[i].SchoolName == 'M')
				sch[0].BoyScore += ChenJiBiao[i].Grade;
				else sch[0].GirlScore += ChenJiBiao[i].Grade;
				sch[0].SumScore += ChenJiBiao[i].Grade;
				break;
				case 'B':
				if(ChenJiBiao[i].SchoolName == 'M')
				sch[1].BoyScore += ChenJiBiao[i].Grade;
				else sch[1].GirlScore += ChenJiBiao[i].Grade;
				sch[1].SumScore += ChenJiBiao[i].Grade;
				break;
				case 'C':
				if(ChenJiBiao[i].SchoolName == 'M')
				sch[2].BoyScore += ChenJiBiao[i].Grade;
				else sch[2].GirlScore += ChenJiBiao[i].Grade;
				sch[2].SumScore += ChenJiBiao[i].Grade;
				break;
				case 'D':
				if(ChenJiBiao[i].SchoolName == 'M')
				sch[3].BoyScore += ChenJiBiao[i].Grade;
				else sch[3].GirlScore += ChenJiBiao[i].Grade;
				sch[3].SumScore += ChenJiBiao[i].Grade;
				break;
				case 'E':
				if(ChenJiBiao[i].SchoolName == 'M')
				sch[4].BoyScore += ChenJiBiao[i].Grade;
				else sch[4].GirlScore += ChenJiBiao[i].Grade;
				sch[4].SumScore += ChenJiBiao[i].Grade;
				break;
				
		}
	}
	
}
void PrintBiao(Dandu sch[])		//打印成绩 
{
	int i;
	for( i = 0; i < 5; i++)
	{
		printf("%c学校男生成绩为%d, 女生成绩为%d,总成绩为%d\n",'A' + i,sch[i].BoyScore,sch[i].GirlScore,sch[i].SumScore);
	}
}
void Init(Dandu sch[])		//初始化函数 
{
	int i;
	for( i = 0; i < 5; i++)
	{
		sch[i].BoyScore = 0;
		sch[i].GirlScore = 0;
		sch[i].SumScore = 0;
	}
}
int main()	
{

	Sc ChenJiBiao[MAX];	//建立成绩总表 
	Dandu sch[5];	//各学校成绩表 
	Init(sch);		//初始化各个成绩表 
	int biaochang;
	biaochang = LuRu(ChenJiBiao);	//成绩录入 
	ChuLi(ChenJiBiao,sch,biaochang);	//成绩处理 
	PrintBiao(sch);	//成绩打印 
	return 0;
}
