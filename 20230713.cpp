#include "linkedlist.h"

int main()
{
	LinkedList li;

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
			li.InsertRear(no, str);
		}
		else if (pick == 2)
		{
			cout << "��ȣ �Է�: ";
			cin >> no;
			li.Remove(no);
		}
		else if (pick == 3)
		{
			li.Print();
		}
	}

	return 0;
}