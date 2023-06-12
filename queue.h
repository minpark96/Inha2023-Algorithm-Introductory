#pragma once
#ifndef ___Queue
#define ___Queue
#include <iostream>
#include <string>

class Queue
{
private:
	int max;
	int num;
	int front;
	int rear;
	std::string* que;
public:
	Queue();
	~Queue();
	bool Initialize(int max);
	bool Enque(std::string x);
	bool Deque(std::string& x);
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
#endif // !___IntQueue