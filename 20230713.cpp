#include "linkedlist.h"

int main()
{
	LinkedList li;

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
			li.InsertRear(no, str);
		}
		else if (pick == 2)
		{
			cout << "번호 입력: ";
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