void Next(string det, int* next)
{
    int i = 1, j = 0;
    next[1] = 0;
    int len = det.size();
    while (i < len)
    {
        if (j == 0 || det[i - 1] == det[j - 1])
        {
            ++i, ++j;
            if (det[i - 1] != det[j - 1])
                next[i] = j;
            else
                next[i] = next[j];
        }
        j = next[j];
    }
}

int kmp(string det, string src)
{
    int len1 = det.size();
    int len2 = src.size();
    int i = 1, j = 1;
    int next[20];;
    Next(src, next);
    while (i <= len1 && j <= len2)
    {
        if (j == 0 || det[i - 1] == src[j - 1])
        {
            ++i, ++j;
        }
        else
            j = next[j];
    }

    if (j > len2)
        return i - len2 - 1;
    else
        return -1;
}