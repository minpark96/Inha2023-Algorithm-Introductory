#include <iostream>
#include "stack.h"

int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	s->stk = new(std::nothrow) int[max];
	if (!s->stk)
	{ 
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x)
{
	if (IsFull(s))
		return -1;
	s->stk[Size(s)] = x;
	s->ptr++;
	return 0;
}

int Pop(IntStack* s, int* x)
{
	if (IsEmpty(s))
		return -1;
	*x = s->stk[Size(s) - 1];
	s->ptr--;
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (IsEmpty(s))
		return -1;
	*x = s->stk[Size(s) - 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

int IsEmpty(const IntStack* s)
{
	return s->ptr == 0;
}

int IsFull(const IntStack* s)
{
	return s->ptr == s->max;
}

int Search(const IntStack* s, int x)
{
	if (IsEmpty(s))
		return -1;
	for (int i = 1; i < Size(s); i++)
	{
		if (s->stk[i] == x)
			return 0;
	}
	return -1;
}

void Print(const IntStack* s)
{
	using namespace std;
	if (IsEmpty(s))
	{
		cout << "스택에 데이터가 없습니다." << endl;
		return;
	}
	for (int i = 0; i < Size(s); i++)
	{
		cout << s->stk[i] << ' ';
	}
	cout << endl;
}

void Terminate(IntStack* s)
{
	delete s->stk;
}