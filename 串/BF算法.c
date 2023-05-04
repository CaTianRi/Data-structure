
int Index(char* s, char* t, int pos)	//暴力破解法(BF)
{
	int i = pos, j = 0;
	while (i < strlen(s) && j < strlen(t))
	{
		if (s[i] == t[j])
		{
			++i, ++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == strlen(t))
	{
		return i - strlen(t) - pos + 1;
	}

		return 0;
}