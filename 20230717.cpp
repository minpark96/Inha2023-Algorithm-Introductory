#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

struct Node
{
	int no;
	string name;
	int next;
};

struct List
{
	int head;
	int curr;
	int tail;
};

struct F_List
{
	int head;
	int tail;
	int size;
};

void Init(Node* li, int* f_li, List& info, F_List& f_info);
void Insert(int& no, string& name, Node* li, int* f_li, List& info, F_List& f_info);
void Remove(int& no, Node* li, int* f_li, List& info, F_List& f_info);
void Print(Node* li, List& info);

int main()
{
	Node li[SIZE];
	int f_li[SIZE];
	List info;
	F_List f_info;
	Init(li, f_li, info, f_info);

	while (true)
	{
		int pick;
		int no;
		string str;
		cout << "(1)�Է� (2)���� (3)��ü ��� (0)����\n";
		cout << "���� > ";
		cin >> pick;

		if (pick == 0)
			break;
		else if (pick == 1)
		{
			cout << "��ȣ �Է�: ";
			cin >> no;
			cin.ignore();
			cout << "�̸� �Է�: ";
			getline(cin, str);
			Insert(no, str, li, f_li, info, f_info);
		}
		else if (pick == 2)
		{
			cout << "��ȣ �Է�: ";
			cin >> no;
			Remove(no, li, f_li, info, f_info);
		}
		else if (pick == 3)
		{
			Print(li, info);
		}
	}

	return 0;
}

void Init(Node* li, int* f_li, List& info, F_List& f_info)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		f_li[i] = i + 1;
	}
	f_li[SIZE - 1] = -1;

	info.head = -1; 
	info.curr = -1;
	info.tail = -1;
	
	f_info.head = 0;
	f_info.size = SIZE;
	f_info.tail = SIZE - 1;
}

void Insert(int& no, string& name, Node* li, int* f_li, List& info, F_List& f_info)
{
	if (f_info.size == 0)
	{
		// ����Ʈ full
		cout << "����Ʈ�� �����ֽ��ϴ�!" << endl;
	}
	else
	{
		int idx;

		idx = f_info.head;
		f_info.head = f_li[f_info.head];
		f_li[idx] = -1;

		li[idx].no = no;
		li[idx].name = name;
		li[idx].next = -1;

		if (f_info.size == SIZE)
		{
			// ��忡 ����ֱ�
			info.head = idx;
			info.tail = idx;
		}
		else
		{
			// ������ ����ֱ�
			li[info.tail].next = idx;
			info.tail = idx;
		}

		f_info.size--;
	}
}

void Remove(int& no, Node* li, int* f_li, List& info, F_List& f_info)
{
	if (f_info.size == SIZE)
	{
		cout << "����Ʈ�� ����ֽ��ϴ�!" << endl;
	}
	else
	{
		
		info.curr = info.head;
		int prev = info.head;
		while (info.curr != -1)
		{
			if (li[info.curr].no == no)
			{
				// �߰� �� ����
				if (info.curr == info.head)
				{
					// �Ӹ���
					info.head = li[info.curr].next;
				}
				else if (info.curr == info.tail)
				{
					// ������
					info.tail = prev;
					li[prev].next = -1;
				}
				else
				{
					// �߰���
					li[prev].next = li[info.curr].next;
				}
				li[info.curr].next = -1;

				if (f_info.size == 0)
				{
					// ���� ����Ʈ�� �������
					f_info.head = info.curr;
				}
				f_li[f_info.tail] = info.curr;
				f_li[info.curr] = -1;
				f_info.size++;
				cout << no << "���� �����߽��ϴ�!\n";
				return;
			}
			else
			{
				// �߰� ����
				prev = info.curr;
				info.curr = li[info.curr].next;
			}
		}
		
		cout << no << "���� �������� �ʽ��ϴ�!\n";
	}
}

void Print(Node* li, List& info)
{
	if (info.head == -1)
	{
		cout << "����Ʈ�� ����ֽ��ϴ�!" << endl;
	}
	else
	{
		info.curr = info.head;
		while (info.curr != -1)
		{
			cout << "��ȣ: " << li[info.curr].no << ", �̸�: " << li[info.curr].name << endl;
			info.curr = li[info.curr].next;
		}
	}
}