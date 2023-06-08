#include <iostream>
#include "stack.h"

int main()
{
	using namespace std;
	IntStack s;
	if (Initialize(s, 64) == -1)
	{
		cout << "���� ������ �����߽��ϴ�." << endl;
		return 1;
	}

	while (true)
	{
		int menu, x;
		cout << "���� ������ ��: " << Size(s) << '/' << Capacity(s) << endl;
		cout << "(1)Ǫ�� (2)�� (3)��ũ (4)Ŭ���� (5)�˻� (6)��� (0)����: ";
		cin >> menu;
		
		if (!menu)
			break;

		switch (menu)
		{
		case 1:
			cout << "������: ";
			cin >> x;
			if (Push(s, x) == -1)
				cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
			break;
		case 2:
			if (Pop(s, x) == -1)
				cout << "\a����: �˿� �����߽��ϴ�." << endl;
			else
				cout << "�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;
		case 3:
			if (Peek(s, x) == -1)
				cout << "\a����: ��ũ�� �����߽��ϴ�." << endl;
			else
				cout << "��ũ �����ʹ� " << x << "�Դϴ�." << endl;
			break;
		case 4:
			Clear(s);
			break;
		case 5:
			cout << "�˻� ������: ";
			cin >> x;
			if(Search(s, x) == -1)
				cout << "\a����: �˻��� �����߽��ϴ�." << endl;
			else
				cout << x << "�� ���� �� �����մϴ�." << endl;
			break;
		case 6:
			Print(s);
			break;
		}
	}

	Terminate(s);
	return 0;
}
