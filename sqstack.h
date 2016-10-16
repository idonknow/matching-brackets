#include<malloc.h>

#define Elemtype char
#define StackSize 33

typedef struct 
{
    Elemtype *data;
    int size;
    Elemtype *top;
}SqStack;

SqStack InitStack(int size = 10)
{   //initialize a stack
	SqStack s;
	s.data = (Elemtype*)malloc(sizeof(Elemtype) * size);
	s.size = size;
	s.top = s.data;
	return s;
}

void DestroyStack(SqStack &s)
{
	free(s.data);
	s.top = s.data;
	s.size = 0;
}

int GetTop(SqStack &s, Elemtype &e)
{
	if (s.top == s.data)
		return 0;
	e = *(s.top - 1);
	return 1;
}

void Push(SqStack &s, Elemtype e)
{
	*s.top++ = e;
}

int Pop(SqStack &s, Elemtype &e)
{
	if (s.top == s.data)
		return 0;
	s.top--;
	e = *(s.top);
	return 1;
}

int StackEmpty(SqStack s)
{
	if (s.top == s.data)
		return 1;
	else
		return 0;
}