#ifndef HEADER
#define HEADR 1
//用直接插入排序对数组a中的元素进行升序排序
template<class T>
void insertionSort(T a[], int n)
{
	int i,j;
	T temp;

	//将下标从1 ~ n - 1的元素逐个插入到已排序的序列中的适当位置
	for(int i = 1; i < n; i++)//从a[i-1]开始向a[0]方向扫描各个元素，寻找合适的位置插入a[i]
	{
		int j = i;
		T temp = a[i];
		while( j > 0 && temp < a[j - 1])//逐个比较直到temp > a[j - 1]，那么a[j]便是插入位置
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}
#endif