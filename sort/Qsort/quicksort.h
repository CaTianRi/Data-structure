#include <stack>
#include <stdio.h>
#include <stdlib.h>

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int *a, int left, int right);
// 快速排序挖坑法
int PartSort2(int *a, int left, int right);
// 快速排序前后指针法
int PartSort3(int *a, int left, int right);
void QuickSort(int *a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int *a, int left, int right);
