#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity; 
}Heap;

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

void HeapPrint(Heap* hp);

void PrintTopK(int k);

void AdjustDown(HPDataType* a, int n, int parent);

void swap(HPDataType*, HPDataType*);