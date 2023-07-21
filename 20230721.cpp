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
		cout << "(1)추가 (2)삭제 (3)검색 (4)모두 삭제 (5)덤프 (0)종료: ";
		cin >> pick;

		if (pick == (int)MENU::QUIT)
			break;
		else if (pick == (int)MENU::ADD)
		{
			cout << "추가할 데이터를 입력하세요.\n";
			cout << "번호: ";
			cin >> no;
			cin.ignore();
			cout << "이름: ";
			getline(cin, str);
			Data da = { no, str };
			ch.Add(da);
		}
		else
		{
			if (ch.Empty())
			{
				cout << "해시 테이블이 비어있습니다!\n\n";
				continue;
			}
			else if (pick == (int)MENU::REMOVE)
			{
				cout << "삭제할 데이터를 입력하세요.\n";
				cout << "번호: ";
				cin >> no;
				ch.Remove(no);
			}
			else if (pick == (int)MENU::SEARCH)
			{
				cout << "검색할 데이터를 입력하세요.\n";
				cout << "번호 입력: ";
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