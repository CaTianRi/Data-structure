#include "Heap.h"
#include <assert.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 推送测试

void HeapDestory(Heap *hp)
{
    free(hp->_a);
    hp->_capacity = hp->_capacity = 0;
}

void swap(HPDataType* A, HPDataType* B)
{
    HPDataType tem = *A;
    *A = *B;
    *B = tem;
}

void HeapPrint(Heap *hp)
{
    for(int i = 0; i < hp->_size; ++i)
    {
        printf("%d ", hp->_a[i]);
    }
    printf("\n");
}

void HeapInit(Heap* hp)
{
    hp->_a = NULL;
    hp->_size = hp->_capacity = 0;
}

void AdjustUp(HPDataType* a, int child)
{
    int parent = (child - 1) / 2;
    while(child > 0)
    {
        if(a[child] > a[parent])
        {
            swap(&a[child], &a[parent]);
            child = parent;
            parent = (parent-1) / 2;
        }
        else 
            break;
    }
}

void HeapCreate(Heap *hp, HPDataType *a, int n)
{
    HeapInit(hp);
    hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    if(!hp->_a)
    {
        exit(-1);
    }

    memcpy(hp->_a, a, sizeof(HPDataType) * n);
    hp->_size = hp->_capacity = n;

    for(int i = 1; i < n; ++i)
    {
        AdjustUp(hp->_a, i);
    }
}


void HeapPush(Heap *hp, HPDataType x)
{
    assert(hp);

    if(hp->_size == hp->_capacity)
    {
        int capacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
        Heap* tem = (Heap*)realloc(hp, sizeof(Heap) * capacity);
        if(!tem)
            exit(-1);
    }
    hp->_a[hp->_size++] = x;

    AdjustUp(hp->_a, hp->_size - 1);
}

void AdjustDown(HPDataType* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child + 1 < n && a[child + 1] < a[child])
        {
            ++child;
        }

        if(a[child] < a[parent])
        {
            swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else 
            break;
    }
}

void HeapPop(Heap *hp)
{
    assert(hp);
    assert(hp->_size > 0);

    swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
    hp->_size--;
    
    AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
    assert(hp->_size);

    return hp->_a[0];
}

int HeapSize(Heap* hp)
{
    return hp->_size;
}

int HeapEmpty(Heap* hp)
{
    return hp->_size == 0;
}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
    FILE* file = fopen("./data.txt", "r");
    if(!file)
        exit(-2);

    int* nums = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; ++i)
    {
        fscanf(file, "%d", &nums[i]);
    }

    for(int i = (k-2) / 2; i >= 0; --i)
    {
        AdjustDown(nums, k, i);
    }

    int x = 0;

    while(fscanf(file, "%d", &x) != EOF)
    {
        if(x > nums[0])
        {
            swap(&nums[0], &x);
            AdjustDown(nums, k, 0);
        }
    }

    int end = k - 1;
    while(end)
    {
        swap(&nums[0], &nums[end--]);
        AdjustDown(nums, end, 0);
    }

    for(int i = 0; i < k; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}   

