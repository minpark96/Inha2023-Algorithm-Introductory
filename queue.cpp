#include <iostream>
#include <string>
#include "queue.h"

Queue::Queue()
{
	front = 0;
	rear = 0;
	num = 0;
	que = 0;
	max = 0;
}

Queue::~Queue()
{
}

bool Queue::Initialize(int max)
{
	this->max = max;
	que = new(std::nothrow) std::string[max];
	if (!que)
	{
		this->max = 0;
		return 0;
	}
	return 1;
}

bool Queue::Enque(std::string x)
{
	if (IsFull())
		return 0;
	if (IsEmpty())
	{
		que[rear] = x;
		num++;
	}
	else
	{
		if (rear == Capacity() - 1)
		{
			rear = 0;
			que[rear] = x;
			num++;
		}
		else
		{
			rear++;
			que[rear] = x;
			num++;
		}
	}
	return 1;
}

bool Queue::Deque(std::string& x)
{
	if (IsEmpty())
		return 0;
	if (front == rear)
	{
		x = que[front];
		num--;
	}
	else
	{
		if (front == Capacity() - 1)
		{
			x = que[front];
			front = 0;
			num--;
		}
		else
		{
			x = que[front];
			front++;
			num--;
		}
	}
	return 1;
}

bool Queue::Peek(std::string& x) const
{
	if (IsEmpty())
		return 0;
	x = que[front];
	return 1;
}

void Queue::Clear()
{
	num = 0;
	front = 0;
	rear = 0;
}

int Queue::Capacity() const
{
	return max;
}

int Queue::Size() const
{
	return num;
}

bool Queue::IsEmpty() const
{
	return num == 0;
}

bool Queue::IsFull() const
{
	return num == max;
}

bool Queue::Search(std::string x) const
{
	if (IsEmpty())
		return 0;
	if (rear < front)
	{
		for (int i = front; i < Capacity(); i++)
		{
			if (que[i] == x)
				return 1;
		}
		for (int i = 0; i < rear + 1; i++)
		{
			if (que[i] == x)
				return 1;
		}
	}
	else
	{
		for (int i = front; i < rear + 1; i++)
		{
			if (que[i] == x)
				return 1;
		}
	}
	return 0;
}

void Queue::Print() const
{
	if (IsEmpty())
	{
		std::cout << "큐에 데이터가 없습니다." << std::endl;
		return;
	}
		
	if (rear < front)
	{
		for (int i = front; i < Capacity(); i++)
		{
			std::cout << que[i] << ' ';
		}
		for (int i = 0; i < rear + 1; i++)
		{
			std::cout << que[i] << ' ';
		}
	}
	else
	{
		for (int i = front; i < rear + 1; i++)
		{
			std::cout << que[i] << ' ';
		}
	}
	std::cout << std::endl;
}

void Queue::Terminate()
{
	delete[] que;
}