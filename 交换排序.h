#ifndef HEADER_2
#define HEADER_2

template<class T>
void bubbleSort(T a[],int n)
{
	int i = n - 1;
	while(i > 0)
	{
		int leastExchangeIndex = 0;
		for(int j = 0; j < n - 1; j++)
			if(a[j + 1] < a[j])
			{
				mySwap(a[j], a[j + 1]);
				leastExchangeIndex = j;
			}
			i = leastExchangeIndex;
	}
}
#endif
