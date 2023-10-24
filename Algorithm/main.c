int Addition(string s1, string s2, int* sum)
{
    int len1 = s1.size();
    int len2 = s1.size();
    int a2[1000] = { 0 };
    int len = len1 > len2 ? len1 : len2;
    for (int i = len1 - 1, j = 0; i >= 0; --i, ++j)
    {
        sum[j] = s1[i] - '0';
    }

    for (int i = len2 - 1, j = 0; i >= 0; --i, ++j)
    {
        a2[j] = s2[i] - '0';
    }

    for (int i = 0; i < len; ++i)
    {
        sum[i] += a2[i];
        if (sum[i] > 9)
        {
            sum[i + 1]++;
            sum[i] -= 10;
        }
    }
    if (sum[len])
        len++;

    return len;
}