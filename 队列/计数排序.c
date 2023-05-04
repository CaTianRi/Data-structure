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