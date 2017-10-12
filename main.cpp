#include<iostream>
#include<stdio.h>
#include"直接插入排序.h"
#include"直接选择排序.h"
#include"交换排序.h"
	using namespace std;
template<class T>
void copyArray(T a[], T b[],int n)//复制数组a到b中
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];

}

template<class T>
void readArray(T a[],int n)	//读入数组
{
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

template<class T>
void writeArray(T a[],int n)//打印数组
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}

int main(void)
{
	int a[5],b[5];
	readArray(a,5);
	writeArray(a,5);

	copyArray(a,b,5);
	//直接插入排序
	insertionSort(b,5);
	writeArray(b,5);

	copyArray(a,b,5);
	//直接选择排序
	selectionSort(b,5);
	writeArray(b,5);

	copyArray(a,b,5);
	//交换排序
	bubbleSort(b,5);
	writeArray(b,5);
	
	writeArray(a,5);

	return 0;

}

