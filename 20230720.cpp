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
		cout << "(1)삽입 (2)삭제 (3)검색 (4)출력 (0)종료\n";
		cout << "선택 > ";
		cin >> pick;

		if (pick == (int)MENU::QUIT)
			break;
		else if (pick == (int)MENU::INSERT)
		{
			cout << "번호 입력: ";
			cin >> no;
			cin.ignore();
			cout << "이름 입력: ";
			getline(cin, str);
			Data da = { no, str };
			bt.Insert(da);
		}
		else
		{
			if (bt.Empty())
			{
				cout << "트리가 비어있습니다!\n\n";
				continue;
			}
			else if (pick == (int)MENU::REMOVE)
			{
				cout << "번호 입력: ";
				cin >> no;
				if(!bt.Remove(no))
					cout << no << "번은 존재하지 않습니다!\n";
			}
			else if (pick == (int)MENU::SEARCH)
			{
				cout << "번호 입력: ";
				cin >> no;
				Node* tmp = bt.Search(no);
				if (tmp != nullptr)
					cout << tmp->data.no << ' ' << tmp->data.name << "\n";
				else
					cout << no << "번은 존재하지 않습니다!\n";
			}
			else if (pick == (int)MENU::PRINT)
			{
				cout << "[모든 노드 출력]\n";
				bt.Print(bt.GetRoot());
			}
		}

		cout << "\n";
	}

	return 0;
}