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


			for (j = i; j <= end2; ++j)
			{
				a[j] = temp[j];
			}
		}
		grap *= 2;
	}
	free(temp);
}