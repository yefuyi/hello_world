#include<stdio.h> 
#include<string.h>
#define MAX 100
typedef struct Score	//	�ܳɼ��� 
{
	char SchoolName;
	char Gender;
	char SportName[10];
	float Score;
	int Grade;
}Sc;
typedef struct School		//����ѧУ�ɼ��� 
{
	int BoyScore;
	int GirlScore;
	int SumScore;
}Dandu;
int LuRu(Sc ChengJiBiao[])	//¼��ɼ� 
{
	int i,j;
	j = 0;
	printf("�Ƿ�����ɼ���(0 --> no , 1 ---> yes): ");
	scanf("%d",&i);
	while(i != 0)
	{
		printf("������Ŀ����: ");
		scanf("%s",ChengJiBiao[j].SportName);
		getchar();
		printf("�����Ա�(M or W): ");
		scanf("%c",&ChengJiBiao[j].Gender);
		getchar();		//���ջس����� 
		printf("����У��: ");
		scanf("%c",&ChengJiBiao[j].SchoolName);	
		printf("����ɼ�: ");
		scanf("%f",&ChengJiBiao[j].Score);
		printf("����÷�: ");
		scanf("%d",&ChengJiBiao[j].Grade);
		j++;
		printf("�Ƿ�����ɼ���(0 --> no , 1 ---> yes): ");
		scanf("%d",&i);
	}
	return j;
	
}
void ChuLi(Sc ChenJiBiao[], Dandu sch[],int n)		//�ɼ�ͳ�� 
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
void PrintBiao(Dandu sch[])		//��ӡ�ɼ� 
{
	int i;
	for( i = 0; i < 5; i++)
	{
		printf("%cѧУ�����ɼ�Ϊ%d, Ů���ɼ�Ϊ%d,�ܳɼ�Ϊ%d\n",'A' + i,sch[i].BoyScore,sch[i].GirlScore,sch[i].SumScore);
	}
}
void Init(Dandu sch[])		//��ʼ������ 
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

	Sc ChenJiBiao[MAX];	//�����ɼ��ܱ� 
	Dandu sch[5];	//��ѧУ�ɼ��� 
	Init(sch);		//��ʼ�������ɼ��� 
	int biaochang;
	biaochang = LuRu(ChenJiBiao);	//�ɼ�¼�� 
	ChuLi(ChenJiBiao,sch,biaochang);	//�ɼ����� 
	PrintBiao(sch);	//�ɼ���ӡ 
	return 0;
}
