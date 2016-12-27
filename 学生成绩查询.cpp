/*叶姜豪 14信息与计算科学 课程练习题 修改日期2016/12/27*/
#include<iostream>
#include<string>
#include<stdio.h>
	using namespace std;
#define KG "    "
#define XX "------------------"
#define XH "*********"

class Date{				//时间类函数
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
	cout  << Year << "年" << Month << "月" << Day << "日"  << endl;
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
class People{  //People类函数
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
		string GetName(){return name;}		//读取姓名接口 
		void NameIs(){			//初始化姓名接口 
			cout << "姓名: ";
			cin >> name;
		}
		void inline ShowInfo(){
			cout <<  XX << "编号" << number  << XX<<endl;
			cout << "姓名: " << name << endl;
			cout << "性别: " << sex << endl;
            cout << "出生日期: " ;
			birthday.ShowDate();
			cout <<  "年龄: " << age << endl;
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
	cout <<  XX << "编号" << number  << XX<<endl;
	cout << "姓名: ";
	cin >> name;
	cout << "性别: ";
	cin >> sex;
	cout << "出生日期: "<< endl;
	birthday.GetDate();
	cout << "年龄: ";
	cin >> age;
	if(age >= Odest) Odest = age;
	count++;
	Average  = ((count - 1) * Average + age ) / count;
}

class Score   //成绩
{
public:
	void GetScore();
	void ShowScore();
private:
	float c_grade,math_grade,english_grade;
};
void Score::GetScore()
{
	cout << "C语言成绩: ";
	cin >> c_grade;
	cout << "数学成绩: ";
	cin >> math_grade;
	cout << "英语成绩: ";
	cin >> english_grade;
}
void Score::ShowScore()
{
	cout <<"C语言成绩: " << c_grade << "  数学成绩: " << math_grade << "   英语成绩: " << english_grade << endl;
	
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


void Student::GetStudInfo(){ //学生类
	NameIs(); 
	cout << "学号: ";
	cin >> ID;
	cout << "年级: ";
	cin >> r;
	cout << "专业: " ;
	cin >> c;
	MyScore.GetScore();
}
void Student::ShowStudInfo(){
	cout <<  XX << XX << XX<<endl;
	cout << "姓名: " << GetName() << "  " << "学号: " << ID <<endl;
	cout << "年级 " << r << endl;
	cout << "专业 " << c << endl;
	MyScore.ShowScore();
	cout <<  XX << XX << XX<<endl;

}
class Teacher :virtual  public People{ //教师类
public:
	void GetTeachInfo();
	void ShowTeachInfo();
private:
	string ZW, BM , ZC,ID;
};
void Teacher::GetTeachInfo(){
	NameIs();
	cout << "工号 : ";
	cin >> ID;
	cout << "职务 : ";
	cin >> ZW;
	cout << "部门 : " ;
	cin >> BM;
	cout << "职称 : " ;
	cin >> ZC;
}
void Teacher::ShowTeachInfo(){
	cout <<  XX << XX << XX<<endl;
	cout << "姓名: " << GetName() << "  " << "工号: " << ID <<endl; 
	cout << "职务: " << ZW << KG ;
	cout << "部门: " << BM << KG ;
	cout << "职称: " << ZC << endl;
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
	cout << "课程名称: "; 
	cin >> CourseName;
	cout << "课程老师: ";
	course_teacher.GetTeachInfo();
	cout << "课程人数: ";
	cin >> stuNumber;
}
void Course::ShowCourseInfo()
{
	cout <<  XX << XX << XX<<endl;
	cout << "课程老师: " << course_teacher.GetName() << endl;
	cout << "课程人数: " << stuNumber << endl;
}

typedef struct node 
{
	Student stu;
	struct  node *next;
}Node,*Link;

void menu()
{
	system("color 80");
	cout <<"\n" << XH << "查询（1）" << XH << endl;
	cout << XH << "增添（2）" << XH << endl;
	cout << XH << "删除（3）" << XH << endl;
	cout << XH << "显示（4）" << XH << endl;
	cout << XH << "退出（5）" << XH << endl;
}
void Search(Link l)
{
	system("cls") ;
	cout << XX << "元素查询" << XX << endl; 
	string Name;
	cout << "输入姓名: ";
	cin >> Name;
	Node *r;
	r = l -> next;
	if(r == NULL) 
	{
		cout << "学生表为空！！ 请添加元素！！！";
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
	cout << "查到不到相应信息！！！" << endl;
}
void Add(Link l)
{
	system("cls") ;
	static int counter = 0; 
	counter++;		//计数器 
	cout << XX << "增加元素" << XX << endl; 
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
	cout << XX << "删除元素" << XX << endl; 
	string na;
	Node *r  = l;
	cout << "要删除学生的学号: ";
	while(r != NULL)
	{
		if( ((r ->next)->stu).GetID() == na)
		
		{
			r ->next  = (r->next)->next;
			return;
		}
		else r = r->next;
		
	}
	cout << "不存在此学生！！！" << endl;
}
void Disp(Link l)
{
	cout << XX << "显示系统" << XX << endl; 
	system("cls") ;
	Node *r = l->next;
	if(r == NULL) {
		cout << "空表！！！" << endl;
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
	Node *head,*p,*q;
	head = new Node;
	head->next = NULL;
	menu();
	int i;
	cout << "输入要进行的操作（1~4）: " ;
	cin >> i;
	while(i != 5)
	{
		switch(i) 
		{
			case 1:Search(head);break;
			case 2:Add(head);break;
			case 3:Del(head);break;
			case 4:Disp(head) ;break;
			default:cout << "退出" << endl; break; 
		}
		menu();
		cout << "\n 输入要进行的操作（1~4）: " ;
		cin >> i;
	}
	return 0;
};	
