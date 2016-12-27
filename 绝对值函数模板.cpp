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
	cout << i << "的绝对值="  << abs(i) << endl;
	cout << j << "的绝对值=" << abs(j) << endl;
	cout << p << "的绝对值="  << abs(p) << endl;
	
	return 0;
}
