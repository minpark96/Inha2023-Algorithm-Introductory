#pragma once
#ifndef ___IntQueue
#define ___IntQueue
class Queue
{
private:
	int max;
	int num;
	int front;
	int rear;
	int* que;
public:
	Queue();
	~Queue();
	int Initialize(int max);
	int Enque(int x);
	int Deque(int& x);
	int Peek(int& x) const;
	void Clear();
	int Capacity() const;
	int Size() const;
	int IsEmpty() const;
	int IsFull() const;
	int Search(int x) const;
	void Print() const;
	void Terminate();
};
#endif // !___IntQueue