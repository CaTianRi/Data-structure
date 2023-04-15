#include "Slist.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* pev = phead;
	while (pev->next != NULL)
	{
		printf("%d->",  pev->data);
		pev = pev->next;
	}
	printf("NULL\n");
}

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newcode = (SLTNode*)malloc(sizeof(SLTNode));
	newcode->data = x;
	newcode->next = NULL;
	return newcode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newcode = BuySListNode(x);
	if (!*pphead)
	{
		*pphead = newcode;
	}
	else
	{
		SLTNode* tem = *pphead;
		while (tem->next != NULL)
		{
			tem = tem->next;
		}
		tem->next = newcode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newcode = BuySListNode(x);
	newcode->next = *pphead;
	*pphead = newcode;
}

void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

void SListPopBack(SLTNode** pphead)
{
	SLTNode* tem = *pphead;
	SLTNode* prv = NULL;
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else 
	{
		while (tem->next != NULL)
		{
			prv = tem;
			tem = tem->next;
		}
		free(tem);
		prv->next = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* newcode = phead;
	while (newcode)
	{
		if (newcode->data == x)
		{
			return newcode;
		}
		newcode = newcode->next;
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (*pphead == pos)
	{
		void SListPushFront(pphead, x);
		return;
	}
	SLTNode* newcode = BuySListNode(x);
	SLTNode* tem = *pphead;
	while (tem->next != pos)
	{
		tem = tem->next;
	}
	tem->next = newcode;
	newcode->next = pos;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead == pos)
	{
		SListPopFront(pphead);
		return;
	}
	SLTNode* newcode = *pphead;
	while (newcode->next != pos)
	{
		newcode = newcode->next;
	}
	newcode->next = pos->next;
	free(pos);
}