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
	cout << "����¼��ѧ������:";
	cin  >> n;
	for( i = 0; i< n; i++)
	{
		cout << "-------��" << i + 1 << "ѧ��-----" << endl;
		cout << "¼��ѧ��:";
		cin >>(p + i)->id;
		cout << "����:";
		cin >> (p + i)->name;
	}
}

void Stud::ShowInfo()
{
	for(int i = 0;i < n; i++)
	{
		cout <<"--------��" << i + 1 << "��ѧ��-----"<< endl;
		cout << "ѧ��Ϊ:" << (p+i)->id<< endl;
		cout << "����Ϊ:" << (p+i)->name << endl;
	}

}
void Stud::AddNode()
{
	n++;
	cout << "����¼��ѧ��:";
	cin >>(p + n - 1)->id;
	cout << "����:";
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