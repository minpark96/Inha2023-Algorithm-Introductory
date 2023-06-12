#include <iostream>
#include <string>
#include "stack.h"

Stack::Stack()
{
	ptr = 0;
	stk = 0;
	max = 0;
}

Stack::~Stack()
{
}

bool Stack::Initialize(int max)
{
	ptr = 0;
	stk = new(std::nothrow) std::string[max];
	if (!stk)
	{ 
		this->max = 0;
		return 0;
	}
	this->max = max;
	return 1;
}

bool Stack::Push(std::string x)
{
	if (IsFull())
		return 0;
	stk[Size()] = x;
	ptr++;
	return 1;
}

bool Stack::Pop(std::string& x)
{
	if (IsEmpty())
		return 0;
	x = stk[Size() - 1];
	ptr--;
	return 1;
}

bool Stack::Peek(std::string& x) const
{
	if (IsEmpty())
		return 0;
	x = stk[Size() - 1];
	return 1;
}

void Stack::Clear()
{
	ptr = 0;
}

int Stack::Capacity() const
{
	return max;
}

int Stack::Size() const
{
	return ptr;
}

bool Stack::IsEmpty() const
{
	return ptr == 0;
}

bool Stack::IsFull() const
{
	return ptr == max;
}

bool Stack::Search(std::string x) const
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

void Stack::Print() const
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

void Stack::Terminate()
{
	delete[] stk;
}