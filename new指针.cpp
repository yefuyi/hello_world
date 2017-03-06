#include<iostream>
	using namespace std;
int main()
{
	int n;
	cout << "请输入一维数组长度: " ;
	cin >> n;
	int *p = new int [n];
	int i;
	cout << "请输入数组元素" << endl;
	for(i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个元素为：";
		cin >> *(p + i);
	}
	cout << "数组元素为: " << endl;
	for (i = 0; i < n; i++)
		cout << *(p + i) << " ";
	cout << endl;
	return 0;
}
