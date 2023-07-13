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
		cout << "����Ʈ�� ����ֽ��ϴ�!" << endl;
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
				cout << no << "���� �����߽��ϴ�!\n";
				return;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
		cout << no << "���� �������� �ʽ��ϴ�!\n";
	}
}

void LinkedList::Print()
{
	if (size == 0)
	{
		cout << "����Ʈ�� ����ֽ��ϴ�!" << endl;
	}
	else
	{
		curr = head;
		while (curr != tail->next)
		{
			cout << "��ȣ: " << curr->no << ", �̸�: " << curr->name << endl;
			curr = curr->next;
		}
	}
}
