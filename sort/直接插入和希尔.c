void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; ++i) 
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

void ShellSort(int* a, int n)
{
	int grap = n;
	while (grap > 1)
	{
		grap = grap / 3 + 1;
		int i = 0;
		for (i = 0; i < n - grap; ++i)
		{
			int end = i;
			int temp = a[end + grap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + grap] = a[end];
					end -= grap;
				}
				else
					break;
			}
			a[end + grap] = temp;
		}
	}
}