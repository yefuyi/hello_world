#ifndef HEADER_1
#define HEADER_1 1
template<class T>
void mySwap(T &x, T &y)//交换x和y的值
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template<class T>
void selectionSort(T a[],int n)//用选择法对n个元素进行升序排序
{
	for(int i = 0; i < n - 1; i++)
	{
		int leastIndex = i;
		for(int j = i + 1; j < n; j++)//在a[i + 1]...a[n - 1]中逐个比较，显示出最小值
			if(a[j] < a[leastIndex])
				leastIndex = j;
			mySwap(a[i],a[leastIndex]);//交换a[i]和其后面最小的元素值
	}

}

#endif
