void AujustDwon(int* a, int n, int root)	//建大堆/小堆
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)	// < end
	{
		if (a[child + 1] > a[child] && child + 1 < n)
			child += 1;

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)	//堆排序
{
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AujustDwon(a, n, i);
	}

	int end = n - 1;
	while(end > 0)	//升序建大堆
	{
		Swap(&a[end], &a[0]);
		AujustDwon(a, end, 0);
		end--;
	}
}


void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1, i = 0;

	while (begin < end)
	{
		int mini = begin, maxi = end;
		for (i = begin; i < end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin, --end;
	}
}