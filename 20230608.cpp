#include <iostream>
#include "queue.h"

int main()
{
	using namespace std;
	Queue queue = Queue();
	if (queue.Initialize(64) == -1)
	{
		cout << "ť ������ �����߽��ϴ�." << endl;
		return 1;
	}

	while (true)
	{
		int menu, x;
		cout << "���� ������ ��: " << queue.Size() << '/' << queue.Capacity() << endl;
		cout << "(1)��ť (2)��ť (3)��ũ (4)Ŭ���� (5)�˻� (6)��� (0)����: ";
		cin >> menu;

		if (!menu)
			break;

		switch (menu)
		{
		case 1:
			cout << "������: ";
			cin >> x;
			if (queue.Enque(x) == -1)
				cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
			break;
		case 2:
			if (queue.Deque(x) == -1)
				cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
			else
				cout << "��ť�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;
		case 3:
			if (queue.Peek(x) == -1)
				cout << "\a����: ��ũ�� �����߽��ϴ�." << endl;
			else
				cout << "��ũ�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;
		case 4:
			queue.Clear();
			break;
		case 5:
			cout << "�˻� ������: ";
			cin >> x;
			if (queue.Search(x) == -1)
				cout << "\a����: �˻��� �����߽��ϴ�." << endl;
			else
				cout << x << "��(��) ť �� �����մϴ�." << endl;
			break;
		case 6:
			queue.Print();
			break;
		}
	}

	queue.Terminate();
	return 0;
}