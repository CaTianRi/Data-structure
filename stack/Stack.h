#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef int STDataType;

typedef struct Stack	//�����ʵ��....
{
	STDataType *a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestory(ST* ps);

void StackPush(ST* ps, STDataType x);		//����ջ��

void StackPop(ST* ps);		//��ջ���ó�

STDataType StackTop(ST* ps);	//�Ż�ջ��������

int StackSize(ST* ps);		//�Ż�������

bool StackEmpty(ST* ps);		//�ж��Ƿ�Ϊ��...