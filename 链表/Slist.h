#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};
typedef struct SListNode SLTNode;

// 不会改变链表的头指针，传一级指针
void SListPrint(SLTNode* phead);

// 可能会改变链表的头指针，传二级指针
void SListPushBack(SLTNode** pphead, SLTDataType x);	//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);	//尾插
void SListPopFront(SLTNode** pphead);		//头删
void SListPopBack(SLTNode** pphead);		//尾删

SLTNode* SListFind(SLTNode* phead, SLTDataType x);	//查找数据x所在的“下标”位置
// 在pos的前面插入x
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
// 删除pos位置的值
void SListErase(SLTNode** phead, SLTNode* pos);

// 有些地方也有这样的
//// 在pos的前面插入x
//void SListInsert(SLTNode** phead, int i, SLTDataType x);
//// 删除pos位置的值
//void SListErase(SLTNode** phead, int i);
