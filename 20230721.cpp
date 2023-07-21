#include "ChainHash.h"

enum class MENU
{
	QUIT,
	ADD,
	REMOVE,
	SEARCH,
	REMOVEALL,
	DUMP,
};

int main()
{
	ChainHash ch;
	ch.Initialize(13);

	while (true)
	{
		int pick;
		int no;
		string str;
		cout << "(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (0)����: ";
		cin >> pick;

		if (pick == (int)MENU::QUIT)
			break;
		else if (pick == (int)MENU::ADD)
		{
			cout << "�߰��� �����͸� �Է��ϼ���.\n";
			cout << "��ȣ: ";
			cin >> no;
			cin.ignore();
			cout << "�̸�: ";
			getline(cin, str);
			Data da = { no, str };
			ch.Add(da);
		}
		else
		{
			if (ch.Empty())
			{
				cout << "�ؽ� ���̺��� ����ֽ��ϴ�!\n\n";
				continue;
			}
			else if (pick == (int)MENU::REMOVE)
			{
				cout << "������ �����͸� �Է��ϼ���.\n";
				cout << "��ȣ: ";
				cin >> no;
				ch.Remove(no);
			}
			else if (pick == (int)MENU::SEARCH)
			{
				cout << "�˻��� �����͸� �Է��ϼ���.\n";
				cout << "��ȣ �Է�: ";
				cin >> no;
				ch.Search(no);
			}
			else if (pick == (int)MENU::REMOVEALL)
			{
				ch.RemoveAll();
			}
			else if (pick == (int)MENU::DUMP)
			{
				ch.Dump();
			}
		}

		cout << "\n";
	}

	return 0;
}