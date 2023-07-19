#include "linkedlist.h"

int main()
{
	LinkedList li;

	while (true)
	{
		int pick;
		int no;
		string str;
		cout << "(1)입력 <앞> (2)입력 <뒤> (3)삭제 (4)출력 <정방향> (5)출력 <역방향> (0)종료\n";
		cout << "선택 > ";
		cin >> pick;

		if (pick == 0)
			break;
		else if (pick == 1 || pick == 2)
		{
			cout << "번호 입력: ";
			cin >> no;
			cin.ignore();
			cout << "이름 입력: ";
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
				cout << "리스트가 비어있습니다!\n\n";
				continue;
			}
			else if (pick == 3)
			{
				cout << "번호 입력: ";
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