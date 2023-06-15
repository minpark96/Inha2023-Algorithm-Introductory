#include <iostream>
#include <string>
#include "int_stack.h"

IntStack::IntStack()
{
	ptr = 0;
	stk = 0;
	max = 0;
}

IntStack::~IntStack()
{
}

bool IntStack::Initialize(int max)
{
	ptr = 0;
	stk = new(std::nothrow) int[max];
	if (!stk)
	{
		this->max = 0;
		return 0;
	}
	this->max = max;
	return 1;
}

bool IntStack::Push(int x)
{
	if (IsFull())
		return 0;
	stk[Size()] = x;
	ptr++;
	return 1;
}

bool IntStack::Pop(int& x)
{
	if (IsEmpty())
		return 0;
	x = stk[Size() - 1];
	ptr--;
	return 1;
}

bool IntStack::Peek(int& x) const
{
	if (IsEmpty())
		return 0;
	x = stk[Size() - 1];
	return 1;
}

void IntStack::Clear()
{
	ptr = 0;
}

int IntStack::Capacity() const
{
	return max;
}

int IntStack::Size() const
{
	return ptr;
}

bool IntStack::IsEmpty() const
{
	return ptr == 0;
}

bool IntStack::IsFull() const
{
	return ptr == max;
}

bool IntStack::Search(int x) const
{
	if (IsEmpty())
		return 0;
	for (int i = 0; i < Size(); i++)
	{
		if (stk[i] == x)
			return 1;
	}
	return 0;
}

void IntStack::Print() const
{
	using namespace std;
	if (IsEmpty())
	{
		cout << "스택에 데이터가 없습니다." << endl;
		return;
	}
	for (int i = 0; i < Size(); i++)
	{
		cout << stk[i] << ' ';
	}
	cout << endl;
}

void IntStack::NewPrint(const int x) const
{
	using namespace std;
	if (x > Size() - 1)
		cout << "[ ]";
	else
		cout << "[" << stk[x] << "]";
}

void IntStack::Terminate()
{
	delete[] stk;
}