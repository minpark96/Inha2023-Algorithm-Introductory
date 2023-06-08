#include <iostream>
#include "stack.h"

int main()
{
	using namespace std;
	IntStack s;
	if (Initialize(s, 64) == -1)
	{
		cout << "스택 생성에 실패했습니다." << endl;
		return 1;
	}

	while (true)
	{
		int menu, x;
		cout << "현재 데이터 수: " << Size(s) << '/' << Capacity(s) << endl;
		cout << "(1)푸시 (2)팝 (3)피크 (4)클리어 (5)검색 (6)출력 (0)종료: ";
		cin >> menu;
		
		if (!menu)
			break;

		switch (menu)
		{
		case 1:
			cout << "데이터: ";
			cin >> x;
			if (Push(s, x) == -1)
				cout << "\a오류: 푸시에 실패했습니다." << endl;
			break;
		case 2:
			if (Pop(s, x) == -1)
				cout << "\a오류: 팝에 실패했습니다." << endl;
			else
				cout << "팝 데이터는 " << x << "입니다." << endl;
			break;
		case 3:
			if (Peek(s, x) == -1)
				cout << "\a오류: 피크에 실패했습니다." << endl;
			else
				cout << "피크 데이터는 " << x << "입니다." << endl;
			break;
		case 4:
			Clear(s);
			break;
		case 5:
			cout << "검색 데이터: ";
			cin >> x;
			if(Search(s, x) == -1)
				cout << "\a오류: 검색에 실패했습니다." << endl;
			else
				cout << x << "는 스택 상에 존재합니다." << endl;
			break;
		case 6:
			Print(s);
			break;
		}
	}

	Terminate(s);
	return 0;
}
