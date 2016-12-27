#include<iostream>
#include<string>
#include<stdio.h>
	using namespace std;
#define KG "    "
#define XX "------------------"
#define XH "*********"

class Date{				//ʱ���ຯ��
public:
	Date(int Year = 0,int Month = 0, int Day = 0): Year(Year),Month(Month),Day(Day){}
	Date (Date &P){
	Year = P.Year;
	Month = P.Month;
	Day = P.Day;
	}
	void GetDate();
	void GetChange(Date &q){
		Year = q.Year;
		Month = q.Month;
		Day = q.Day;
	}
	void ShowDate(){
	cout  << Year << "��" << Month << "��" << Day << "��"  << endl;
	}
private:
	int Year,Month,Day;
	};

void Date::GetDate(){
	int x,y,z;
	cin >> x >> y >> z;
	this->Year = x;
	this->Month = y;
	this->Day = z;
}
class People{  //People�ຯ��
	public:
		People(){
		number = ++count;
		name = " ";
		sex=' ';
		age = 0;
		Date birthday(0,0,0);
		}
		People(People &pe){
			number = ++count;
			sex = pe.sex;
			age = pe.age;
			birthday.GetChange(pe.birthday);
			Average  = ((count - 1) * Average + age ) / count;
		}
		void GetInfo();
		int GetAge(){return age;}
		int GetOde(){return Odest;}
		float GetAverage(){return Average;}
		string GetName(){return name;}		//��ȡ�����ӿ� 
		void NameIs(){			//��ʼ�������ӿ� 
			cout << "����: ";
			cin >> name;
		}
		void inline ShowInfo(){
			cout <<  XX << "���" << number  << XX<<endl;
			cout << "����: " << name << endl;
			cout << "�Ա�: " << sex << endl;
            cout << "��������: " ;
			birthday.ShowDate();
			cout <<  "����: " << age << endl;
			cout <<  XX << XX << XX<<endl;
		}
		private:
			int number,age;
			string sex,name;
			Date birthday;
			static int count,Odest;
			static float Average;
		
};
int People::count = 0;
int People::Odest = 0;
float People::Average = 0;


void People::GetInfo(){
	cout <<  XX << "���" << number  << XX<<endl;
	cout << "����: ";
	cin >> name;
	cout << "�Ա�: ";
	cin >> sex;
	cout << "��������: "<< endl;
	birthday.GetDate();
	cout << "����: ";
	cin >> age;
	if(age >= Odest) Odest = age;
	count++;
	Average  = ((count - 1) * Average + age ) / count;
}

class Score   //�ɼ�
{
public:
	void GetScore();
	void ShowScore();
private:
	float c_grade,math_grade,english_grade;
};
void Score::GetScore()
{
	cout << "C���Գɼ�: ";
	cin >> c_grade;
	cout << "��ѧ�ɼ�: ";
	cin >> math_grade;
	cout << "Ӣ��ɼ�: ";
	cin >> english_grade;
}
void Score::ShowScore()
{
	cout <<"C���Գɼ�: " << c_grade << "  ��ѧ�ɼ�: " << math_grade << "   Ӣ��ɼ�: " << english_grade << endl;
	
}

class Student :virtual public People{
public:
	void GetStudInfo();
	void ShowStudInfo();
	string GetID(){return ID;}
private:
	string r,c,ID;
	float score;
	Score MyScore;
};


void Student::GetStudInfo(){ //ѧ����
	NameIs(); 
	cout << "ѧ��: ";
	cin >> ID;
	cout << "�꼶: ";
	cin >> r;
	cout << "רҵ: " ;
	cin >> c;
	MyScore.GetScore();
}
void Student::ShowStudInfo(){
	cout <<  XX << XX << XX<<endl;
	cout << "����: " << GetName() << "  " << "ѧ��: " << ID <<endl;
	cout << "�꼶 " << r << endl;
	cout << "רҵ " << c << endl;
	MyScore.ShowScore();
	cout <<  XX << XX << XX<<endl;

}
class Teacher :virtual  public People{ //��ʦ��
public:
	void GetTeachInfo();
	void ShowTeachInfo();
private:
	string ZW, BM , ZC,ID;
};
void Teacher::GetTeachInfo(){
	NameIs();
	cout << "���� : ";
	cin >> ID;
	cout << "ְ�� : ";
	cin >> ZW;
	cout << "���� : " ;
	cin >> BM;
	cout << "ְ�� : " ;
	cin >> ZC;
}
void Teacher::ShowTeachInfo(){
	cout <<  XX << XX << XX<<endl;
	cout << "����: " << GetName() << "  " << "����: " << ID <<endl; 
	cout << "ְ��: " << ZW << KG ;
	cout << "����: " << BM << KG ;
	cout << "ְ��: " << ZC << endl;
	cout <<  XX << XX << XX<<endl;
}

class Course
{
public:
	void ShowCourseInfo();
	void GetCourseInfo();
private:
	string CourseName;
	Teacher course_teacher;
	int stuNumber;
};

void Course::GetCourseInfo()
{
	cout << "�γ�����: "; 
	cin >> CourseName;
	cout << "�γ���ʦ: ";
	course_teacher.GetTeachInfo();
	cout << "�γ�����: ";
	cin >> stuNumber;
}
void Course::ShowCourseInfo()
{
	cout <<  XX << XX << XX<<endl;
	cout << "�γ���ʦ: " << course_teacher.GetName() << endl;
	cout << "�γ�����: " << stuNumber << endl;
}

typedef struct node 
{
	Student stu;
	struct  node *next;
}Node,*Link;

void menu()
{
	system("color 80");
	cout <<"\n" << XH << "��ѯ��1��" << XH << endl;
	cout << XH << "����2��" << XH << endl;
	cout << XH << "ɾ����3��" << XH << endl;
	cout << XH << "��ʾ��4��" << XH << endl;
	cout << XH << "�˳���5��" << XH << endl;
}
void Search(Link l)
{
	system("cls") ;
	cout << XX << "Ԫ�ز�ѯ" << XX << endl; 
	string Name;
	cout << "��������: ";
	cin >> Name;
	Node *r;
	r = l -> next;
	if(r == NULL) 
	{
		cout << "ѧ����Ϊ�գ��� �����Ԫ�أ�����";
		return; 
	}
	else
	{
		while(r != NULL)
		{
		
			if  ( (r->stu).GetName() == Name)
			{(r->stu).ShowStudInfo();return;} 
			r = r->next;
		}
	}
	cout << "�鵽������Ӧ��Ϣ������" << endl;
}
void Add(Link l)
{
	system("cls") ;
	static int counter = 0; 
	counter++;		//������ 
	cout << XX << "����Ԫ��" << XX << endl; 
	Node *r;
	r = l;
	while(r->next != NULL) r = r->next;
	Node *p = new Node;
	r->next  = p;
	p->next = NULL;
	p->stu.GetStudInfo();
}
void Del(Link l)
{
	system("cls") ;
	cout << XX << "ɾ��Ԫ��" << XX << endl; 
	string na;
	Node *r  = l->next;
	cout << "Ҫɾ��ѧ����ѧ��: ";
	while(r != NULL)
	{
		if( ((r ->next)->stu).GetID() == na)
		
		{
			r ->next  = (r->next)->next;
			return;
		}
		else r = r->next;
		
	}
	cout << "�����ڴ�ѧ��������" << endl;
}
void Disp(Link l)
{
	cout << XX << "��ʾϵͳ" << XX << endl; 
	system("cls") ;
	Node *r = l->next;
	if(r == NULL) {
		cout << "�ձ�����" << endl;
		return;
	}
	while(r != NULL)	
	{
		r->stu.ShowStudInfo();
		r = r->next;
	}
}
int main()
{
	/*
	Link l;		//��������
	FILE *fp;  //�ļ�ָ��
	int select;		//����������
	char ch ;  //(y,Y,N,n) ѡ���ж�
	int counter = 0; //������ 
	Node *p,*r;
	l = new Node;
	if(!l) 
	{
		cout << "\n ����ռ�ʧ�� "  << endl; 	//	����ռ�ʧ��
		return 0; 
	}
	l->next = NULL;
	r = l;
	fp = fopen("E:\\student.txt","ab+");//�����ļ� 
	if(fp == NULL) 
	{
		cout << "\n �޷��ҵ��ļ���" << endl;
		exit(0);
	}
	while(!feof(fp))
	{
		p = new Node;
		if(!p)
		{
			cout << "\n ����ռ�ʧ�� \n";
			exit(0);
		}
		if(fread(p,sizeof(Node),1,fp) == 1)		//һ�δ��ļ��ж�ȡһ����¼
		{
			p -> next = NULL;	//	ָ����� 
			r -> next  = p;
			r = p;
			counter++;
		} 
	}
	fclose(fp);			//�ر��ļ� 
	*/
	Node *head,*p,*q;
	head = new Node;
	head->next = NULL;
	menu();
	int i;
	cout << "����Ҫ���еĲ�����1~4��: " ;
	cin >> i;
	while(i != 5)
	{
		switch(i) 
		{
			case 1:Search(head);break;
			case 2:Add(head);break;
			case 3:Del(head);break;
			case 4:Disp(head) ;break;
			default:cout << "�˳�" << endl; break; 
		}
		menu();
		cout << "\n ����Ҫ���еĲ�����1~4��: " ;
		cin >> i;
	}
	return 0;
};	
