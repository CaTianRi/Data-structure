#include "merge.h"
#include <string.h>

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0], i = 0, j = 0;
	for (i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}


		if (a[i] < min)
		{
			min = a[i];
		}
	}


	int range = max - min + 1;
	int* newArray = (int*)malloc(sizeof(int) * range);
	if (!newArray)
		exit(-1);


	memset(newArray, 0, sizeof(int) * range);
	for (i = 0; i < n; ++i)
	{
		newArray[a[i] - min]++;
	}


	for (i = 0; i < range; ++i)
	{
		while (newArray[i]--)
		{
			a[j++] = i + min;
		}
	}
}


void MergeSortNonR(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (!temp)
	{
		perror("malloc");
		exit(-1);
	}


	int grap = 1, i = 0, j = 0;


	while (grap < n)
	{
		for (i = 0; i < n; i += 2*grap)
		{
			int begin1 = i, end1 = i + grap - 1;
			int begin2 = i + grap, end2 = i + 2 * grap - 1;
			int index = i;


			if (begin2 >= n)
				break;


			if (end2 >= n)
			{
				end2 = n - 1;
			}


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


			while (begin1 <= end1)
			{
				temp[index++] = a[begin1++];
			}


			while (begin2 <= end2)
			{
				temp[index++] = a[begin2++];
			}

            memcpy(a + i, temp + i, (end2-i+1) * sizeof(int));
		}
		grap *= 2;
	}
	free(temp);
}

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
