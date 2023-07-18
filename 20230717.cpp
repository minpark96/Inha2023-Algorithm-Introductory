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
		cout << "(1)입력 (2)삭제 (3)전체 출력 (0)종료\n";
		cout << "선택 > ";
		cin >> pick;

		if (pick == 0)
			break;
		else if (pick == 1)
		{
			cout << "번호 입력: ";
			cin >> no;
			cin.ignore();
			cout << "이름 입력: ";
			getline(cin, str);
			Insert(no, str, li, f_li, info, f_info);
		}
		else if (pick == 2)
		{
			cout << "번호 입력: ";
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
		// 리스트 full
		cout << "리스트가 꽉차있습니다!" << endl;
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
			// 헤드에 집어넣기
			info.head = idx;
			info.tail = idx;
		}
		else
		{
			// 꼬리에 집어넣기
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
		cout << "리스트가 비어있습니다!" << endl;
	}
	else
	{
		
		info.curr = info.head;
		int prev = info.head;
		while (info.curr != -1)
		{
			if (li[info.curr].no == no)
			{
				// 발견 및 삭제
				if (info.curr == info.head)
				{
					// 머리임
					info.head = li[info.curr].next;
				}
				else if (info.curr == info.tail)
				{
					// 꼬리임
					info.tail = prev;
					li[prev].next = -1;
				}
				else
				{
					// 중간임
					li[prev].next = li[info.curr].next;
				}
				li[info.curr].next = -1;

				if (f_info.size == 0)
				{
					// 프리 리스트가 비어있음
					f_info.head = info.curr;
				}
				f_li[f_info.tail] = info.curr;
				f_li[info.curr] = -1;
				f_info.size++;
				cout << no << "번을 삭제했습니다!\n";
				return;
			}
			else
			{
				// 발견 못함
				prev = info.curr;
				info.curr = li[info.curr].next;
			}
		}
		
		cout << no << "번은 존재하지 않습니다!\n";
	}
}

void Print(Node* li, List& info)
{
	if (info.head == -1)
	{
		cout << "리스트가 비어있습니다!" << endl;
	}
	else
	{
		info.curr = info.head;
		while (info.curr != -1)
		{
			cout << "번호: " << li[info.curr].no << ", 이름: " << li[info.curr].name << endl;
			info.curr = li[info.curr].next;
		}
	}
}