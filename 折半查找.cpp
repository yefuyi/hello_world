#include<iostream>
	using namespace std;
//针对查找表必须是非降序的数组
template <class T>	
int Search(const T list[],int n,const T &key)  //折半查找 
{
	int low = 0;
	int high = n - 1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(key == list[mid])
		return mid;
		else if(key < list[mid])
		high = mid + 1;
		else 
			low = mid + 1;
	}
	return -1;   //如果没有找到则返回-1 
}

int main()   //折半查找里面的数组元素需要呈升序或降序，此处为升序; 
{
	int n,a[10]={1,2,3,4,5,6,7,8,9,10};
	cout << "数组元素为：" << endl;
	for(int i = 0;i < 10 ;i ++)
	cout << a[i] << " ";
	cout << endl;
	cout << "请输入需要查找的元素 n = ";
	cin >> n;
	cout << n <<"在数组中的位置第"  << Search(a,10,n) + 1 << "个元素" << endl;
	
	return 0;
}
