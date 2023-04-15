#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef int STDataType;

typedef struct Stack	//数组的实现....
{
	STDataType *a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestory(ST* ps);

void StackPush(ST* ps, STDataType x);		//放入栈底

void StackPop(ST* ps);		//从栈顶拿出

STDataType StackTop(ST* ps);	//放回栈顶的数据

int StackSize(ST* ps);		//放回数据数

bool StackEmpty(ST* ps);		//判断是否为空...