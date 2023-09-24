void _MergeSort(int* a, int left, int right, int* temp)		//归并排序
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;

	_MergeSort(a, left, mid, temp);			//mid - 1 会导致数组越界
	_MergeSort(a, mid + 1, right, temp);

	//归并
	int index = left;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[index++] = a[begin1++];
		}
		else
		{
			temp[index++] = a[begin2++];
		}
	}

	while(begin1 <= end1)
		temp[index++] = a[begin1++];

	while(begin2 <= end2)
		temp[index++] = a[begin2++];

	for (int i = left; i <= right; ++i)
	{
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n-1, temp);
	free(temp);
}