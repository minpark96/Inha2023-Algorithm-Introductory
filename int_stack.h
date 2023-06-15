#pragma once
#ifndef _INT_STACK
#define _INT_STACK
#include <iostream>

class IntStack
{
private:
	int max;
	int ptr;
	int* stk;
public:
	IntStack();
	~IntStack();
	bool Initialize(int max);
	bool Push(int x);
	bool Pop(int& x);
	bool Peek(int& x) const;
	void Clear();
	int Capacity() const;
	int Size() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool Search(int x) const;
	void Print() const;
	void NewPrint(const int x) const;
	void Terminate();
};
#endif