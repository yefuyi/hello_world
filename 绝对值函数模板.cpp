#include<iostream>
	using namespace std;
template <class T>
T abs(T x)
{
	if(x >= 0) return x;
	else return -x;
}
int main()
{
	int i = -8;
	float j = -6;
	double p = -89.345;
	cout << i << "�ľ���ֵ="  << abs(i) << endl;
	cout << j << "�ľ���ֵ=" << abs(j) << endl;
	cout << p << "�ľ���ֵ="  << abs(p) << endl;
	
	return 0;
}
