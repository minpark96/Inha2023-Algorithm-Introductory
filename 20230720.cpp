#include "BinTree.h"

enum class MENU
{
	QUIT,
	INSERT,
	REMOVE,
	SEARCH,
	PRINT,
};

int main()
{
	BinTree bt;

	while (true)
	{
		int pick;
		int no;
		string str;
		cout << "(1)���� (2)���� (3)�˻� (4)��� (0)����\n";
		cout << "���� > ";
		cin >> pick;

		if (pick == (int)MENU::QUIT)
			break;
		else if (pick == (int)MENU::INSERT)
		{
			cout << "��ȣ �Է�: ";
			cin >> no;
			cin.ignore();
			cout << "�̸� �Է�: ";
			getline(cin, str);
			Data da = { no, str };
			bt.Insert(da);
		}
		else
		{
			if (bt.Empty())
			{
				cout << "Ʈ���� ����ֽ��ϴ�!\n\n";
				continue;
			}
			else if (pick == (int)MENU::REMOVE)
			{
				cout << "��ȣ �Է�: ";
				cin >> no;
				if(!bt.Remove(no))
					cout << no << "���� �������� �ʽ��ϴ�!\n";
			}
			else if (pick == (int)MENU::SEARCH)
			{
				cout << "��ȣ �Է�: ";
				cin >> no;
				Node* tmp = bt.Search(no);
				if (tmp != nullptr)
					cout << tmp->data.no << ' ' << tmp->data.name << "\n";
				else
					cout << no << "���� �������� �ʽ��ϴ�!\n";
			}
			else if (pick == (int)MENU::PRINT)
			{
				cout << "[��� ��� ���]\n";
				bt.Print(bt.GetRoot());
			}
		}

		cout << "\n";
	}

	return 0;
}