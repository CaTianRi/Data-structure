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

// ����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLTNode* phead);

// ���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLTNode** pphead, SLTDataType x);	//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);	//β��
void SListPopFront(SLTNode** pphead);		//ͷɾ
void SListPopBack(SLTNode** pphead);		//βɾ

SLTNode* SListFind(SLTNode* phead, SLTDataType x);	//��������x���ڵġ��±ꡱλ��
// ��pos��ǰ�����x
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
// ɾ��posλ�õ�ֵ
void SListErase(SLTNode** phead, SLTNode* pos);

// ��Щ�ط�Ҳ��������
//// ��pos��ǰ�����x
//void SListInsert(SLTNode** phead, int i, SLTDataType x);
//// ɾ��posλ�õ�ֵ
//void SListErase(SLTNode** phead, int i);
