#pragma once
#ifndef ___Stack
#define ___Stack
#include <iostream>
#include <string>

class Stack
{
private:
	int max;
	int ptr;
	std::string* stk;
public:
	Stack();
	~Stack();
	bool Initialize(int max);
	bool Push(std::string x);
	bool Pop(std::string& x);
	bool Peek(std::string& x) const;
	void Clear();
	int Capacity() const;
	int Size() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool Search(std::string x) const;
	void Print() const;
	void Terminate();
};
#endif