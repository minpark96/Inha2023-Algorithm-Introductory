#include "linkedlist.h"

int main()
{
	LinkedList li;

	while (true)
	{
		int pick;
		int no;
		string str;
		cout << "(1)�Է� <��> (2)�Է� <��> (3)���� (4)��� <������> (5)��� <������> (0)����\n";
		cout << "���� > ";
		cin >> pick;

		if (pick == 0)
			break;
		else if (pick == 1 || pick == 2)
		{
			cout << "��ȣ �Է�: ";
			cin >> no;
			cin.ignore();
			cout << "�̸� �Է�: ";
			getline(cin, str);

			if (pick == 1)
				li.InsertFront(no, str);
			else
				li.InsertRear(no, str);
		}
		else
		{
			if (li.Empty())
			{
				cout << "����Ʈ�� ����ֽ��ϴ�!\n\n";
				continue;
			}
			else if (pick == 3)
			{
				cout << "��ȣ �Է�: ";
				cin >> no;
				li.Remove(no);
			}
			else if (pick == 4)
			{
				li.Print();
			}
			else if (pick == 5)
			{
				li.PrintReverse();
			}
		}

		cout << "\n";
	}

	return 0;
}