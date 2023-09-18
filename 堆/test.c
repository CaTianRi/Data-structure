#include "Heap.h"


void HeapSort(int* a, int n)
{
    for(int i = (n-2) / 2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while(end)
    {
        swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

void test()
{
    int a[] = {6,4,2,5,3,7,1,8,0,9};
    HeapSort(a, 10);

    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}



int main()
{
    test();
    return 0;
}
