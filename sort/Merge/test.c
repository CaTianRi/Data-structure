#include "merge.h"
#include <stdio.h>

void test()
{
    int arr[] = {9,8,7,3,5,4,2,1,6,10};
    int arr1[] = {9,8,7,3,5,4,2,1,6,10};

    MergeSort(arr, sizeof(arr) / sizeof(int));
    MergeSortNonR(arr1, sizeof(arr1) / sizeof(int));

    for(int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(int i = 0; i < sizeof(arr1) / sizeof(int); ++i)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");
}

int main()
{
    test();
    return 0;
}
