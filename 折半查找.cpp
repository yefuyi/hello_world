#include<iostream>
	using namespace std;
template <class T>	
int Search(const T list[],int n,const T &key)  //�۰���� 
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
	return -1;   //���û���ҵ��򷵻�-1 
}

int main()   //�۰�������������Ԫ����Ҫ��������򣬴˴�Ϊ����; 
{
	int n,a[10]={1,2,3,4,5,6,7,8,9,10};
	cout << "����Ԫ��Ϊ��" << endl;
	for(int i = 0;i < 10 ;i ++)
	cout << a[i] << " ";
	cout << endl;
	cout << "��������Ҫ���ҵ�Ԫ�� n = ";
	cin >> n;
	cout << n <<"�������е�λ�õ�"  << Search(a,10,n) + 1 << "��Ԫ��" << endl;
	
	return 0;
}
