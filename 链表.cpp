#include<iostream>
#include<string>
	using namespace std;
	struct Student{
		int id;
		string name;
		Student *next;
	};
class Stud
{
public:
	void GetInfo();
	void ShowInfo();
	void AddNode();
private:
	Student p[100];
	int n;

};

void Stud::GetInfo()
{
	int i;
	cout << "输入录入学生个数:";
	cin  >> n;
	for( i = 0; i< n; i++)
	{
		cout << "-------第" << i + 1 << "学生-----" << endl;
		cout << "录入学号:";
		cin >>(p + i)->id;
		cout << "姓名:";
		cin >> (p + i)->name;
	}
}

void Stud::ShowInfo()
{
	for(int i = 0;i < n; i++)
	{
		cout <<"--------第" << i + 1 << "个学生-----"<< endl;
		cout << "学号为:" << (p+i)->id<< endl;
		cout << "姓名为:" << (p+i)->name << endl;
	}

}
void Stud::AddNode()
{
	n++;
	cout << "增加录入学号:";
	cin >>(p + n - 1)->id;
	cout << "姓名:";
	cin >> (p + n - 1)->name;
}
int main()
{
	
	Stud A;
	A.GetInfo();
	A.ShowInfo();
	A.AddNode();
	A.ShowInfo();
	return 0;
}