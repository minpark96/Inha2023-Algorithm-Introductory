#include "linkedlist.h"

LinkedList::LinkedList()
	: head(nullptr)
	, curr(nullptr)
	, size(0)
{
}

LinkedList::~LinkedList()
{
	Node* tmp;
	tmp = head;
	curr = head;
	while (size > 0)
	{
		tmp = curr->next;
		delete curr;
		curr = tmp;
		size--;
	}
}

bool LinkedList::Empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

int LinkedList::Size()
{
	return size;
}

void LinkedList::InsertFront(int& no, string& name)
{
	curr = new Node{ no, name };

	if (size == 0)
	{
		head = curr;
		curr->next = head;
		curr->prev = head;
	}
	else
	{
		curr->next = head;
		curr->prev = head->prev;
		head->prev = curr;
		head->prev->next = curr;
		head = curr;
	}

	size++;
}

void LinkedList::InsertRear(int& no, string& name)
{
	curr = new Node{ no, name };

	if (size == 0)
	{
		head = curr;
		curr->next = head;
		curr->prev = head;
	}
	else
	{
		curr->next = head;
		curr->prev = head->prev;
		head->prev->next = curr;
		head->prev = curr;
	}

	size++;
}

void LinkedList::Remove(int& no)
{
	curr = head;
	do
	{
		if (curr->no == no)
		{
			if (curr == head)
			{
				head->prev->next = curr->next;
				head = curr->next;
				head->prev = curr->prev;
			}
			else if (curr == head->prev)
			{
				head->prev = curr->prev;
				curr->prev->next = head;
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}
			delete curr;
			size--;
			cout << no << "번을 삭제했습니다!\n";
			return;
		}
		else
		{
			curr = curr->next;
		}
	} while (curr != head);
	cout << no << "번은 존재하지 않습니다!\n";
}

void LinkedList::Print()
{
	curr = head;
	do
	{
		cout << "번호: " << curr->no << ", 이름: " << curr->name << endl;
		curr = curr->next;
	} while (curr != head);
}

void LinkedList::PrintReverse()
{
	curr = head->prev;
	do
	{
		cout << "번호: " << curr->no << ", 이름: " << curr->name << endl;
		curr = curr->prev;
	} while (curr != head->prev);
}
