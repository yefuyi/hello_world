#include<iostream>
#include<string> 
	using namespace std;
struct Student
{
	string name;
	string ID;
	Student *next;
};

int main()
{
	Student head;
	char answer;
	int i,j,n;
	cout << "是否添加成员" ;
	cin >> answer;
	while(answer == 'Y')
	{
		Student *p = new Student;
		head->next = p;
		cout << "name: ";
		cin >> p->name;
		cout << "ID: ";
		cin >> p->ID;
	}
	cout << "是否要继续添加成员" ;
	cin >> answer;
	while(answer == 'Y')
	{
		Student *q = new Student;
		cout << "name: ";
		cin >> q->name;
		cout << "ID: ";
		cin >> q->ID;
		p->next = q;
		p = q;
		cout << "是否要继续添加成员" ;
		cin >> answer;
	}
	p->next = NULL;
	for(p = head->next; p->next!=NULL ;p++)
	{
		cout << "Name: " << p->name << endl;
		cout << "ID: " << p->ID << endl;
		p = p->next; 
	}
	return 0;
}
