#include<iostream>
	using namespace std;
int main()
{
	int n;
	cout << "������һά���鳤��: " ;
	cin >> n;
	int *p = new int [n];
	int i;
	cout << "����������Ԫ��" << endl;
	for(i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << "��Ԫ��Ϊ��";
		cin >> *(p + i);
	}
	cout << "����Ԫ��Ϊ: " << endl;
	for (i = 0; i < n; i++)
		cout << *(p + i) << " ";
	cout << endl;
	return 0;
}