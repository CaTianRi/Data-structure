#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->capacity = ps->top = 0;
	ps->a = NULL;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* temp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (!temp)
		{
			perror("StackPush");
			return -1;
		}
		ps->capacity *= 2;
		ps->a = temp;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top-1];   
}


int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

