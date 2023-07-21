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

void LinkedList::InsertFront(const Data da)
{
	curr = new Node{ da };

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
		head = curr;
	}

	size++;
}

void LinkedList::InsertRear(const Data da)
{
	curr = new Node{ da };

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
		if (curr->data.no == no)
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
			cout << no << "���� �����߽��ϴ�!\n";
			return;
		}
		else
		{
			curr = curr->next;
		}
	} while (curr != head);
}

void LinkedList::RemoveAll()
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

	//head = nullptr;
	//curr = nullptr;
}

void LinkedList::Search(int& no)
{
	curr = head;
	do
	{
		if (curr->data.no == no)
		{
			cout << "�˻��� �����߽��ϴ�: " << curr->data.no << ' ' << curr->data.name << "\n";
			return;
		}
		else
		{
			curr = curr->next;
		}
	} while (curr != head);

	cout << "�˻��� �����߽��ϴ�!\n";
}

void LinkedList::Print()
{
	curr = head;
	do
	{
		cout << "�� " << curr->data.no << '(' << curr->data.name << ") ";
		curr = curr->next;
	} while (curr != head);
}

void LinkedList::PrintReverse()
{
	curr = head->prev;
	do
	{
		cout << "��ȣ: " << curr->data.no << ", �̸�: " << curr->data.name << endl;
		curr = curr->prev;
	} while (curr != head->prev);
}
