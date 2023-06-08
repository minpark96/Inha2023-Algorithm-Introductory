#include <iostream>
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

int Queue::Initialize(int max)
{
	this->max = max;
	que = new int[max];
	if (!que)
	{
		this->max = 0;
		return -1;
	}
	return 0;
}

int Queue::Enque(int x)
{
	if (IsFull())
		return -1;
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
	return 0;
}

int Queue::Deque(int& x)
{
	if (IsEmpty())
		return -1;
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
	return 0;
}

int Queue::Peek(int& x) const
{
	if (IsEmpty())
		return -1;
	x = que[front];
	return 0;
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

int Queue::IsEmpty() const
{
	return num == 0;
}

int Queue::IsFull() const
{
	return num == max;
}

int Queue::Search(int x) const
{
	if (IsEmpty())
		return -1;
	if (rear < front)
	{
		for (int i = front; i < Capacity(); i++)
		{
			if (que[i] == x)
				return 0;
		}
		for (int i = 0; i < rear + 1; i++)
		{
			if (que[i] == x)
				return 0;
		}
	}
	else
	{
		for (int i = front; i < rear + 1; i++)
		{
			if (que[i] == x)
				return 0;
		}
	}
	return -1;
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