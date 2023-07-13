#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL;
	curr = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
	if (size == 0)
	{

	}
	else
	{
		Node* next;
		next = head;
		curr = head;
		while (curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
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

void LinkedList::InsertRear(int& no, string& name)
{
	curr = new Node{ no, name };
	curr->next = NULL;

	if (size == 0)
	{
		head = curr;
	}
	else
	{
		tail->next = curr;
	}

	tail = curr;
	size++;
}

void LinkedList::Remove(int& no)
{
	if (size == 0)
	{
		cout << "리스트가 비어있습니다!" << endl;
	}
	else
	{
		Node* prev;
		prev = head;
		curr = head;
		while (curr != tail->next)
		{
			if (curr->no == no)
			{
				if (curr == head)
				{
					head = curr->next;
				}
				else if (curr == tail)
				{
					tail = prev;
					prev->next = NULL;
				}
				else
				{
					prev->next = curr->next;
				}
				delete curr;
				size--;
				cout << no << "번을 삭제했습니다!\n";
				return;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
		cout << no << "번은 존재하지 않습니다!\n";
	}
}

void LinkedList::Print()
{
	if (size == 0)
	{
		cout << "리스트가 비어있습니다!" << endl;
	}
	else
	{
		curr = head;
		while (curr != tail->next)
		{
			cout << "번호: " << curr->no << ", 이름: " << curr->name << endl;
			curr = curr->next;
		}
	}
}
