#include <iostream>
#include "queue.h"

int main()
{
	using namespace std;
	Queue queue = Queue();
	if (queue.Initialize(64) == -1)
	{
		cout << "큐 생성에 실패했습니다." << endl;
		return 1;
	}

	while (true)
	{
		int menu, x;
		cout << "현재 데이터 수: " << queue.Size() << '/' << queue.Capacity() << endl;
		cout << "(1)인큐 (2)디큐 (3)피크 (4)클리어 (5)검색 (6)출력 (0)종료: ";
		cin >> menu;

		if (!menu)
			break;

		switch (menu)
		{
		case 1:
			cout << "데이터: ";
			cin >> x;
			if (queue.Enque(x) == -1)
				cout << "\a오류: 인큐에 실패했습니다." << endl;
			break;
		case 2:
			if (queue.Deque(x) == -1)
				cout << "\a오류: 디큐에 실패했습니다." << endl;
			else
				cout << "디큐한 데이터는 " << x << "입니다." << endl;
			break;
		case 3:
			if (queue.Peek(x) == -1)
				cout << "\a오류: 피크에 실패했습니다." << endl;
			else
				cout << "피크한 데이터는 " << x << "입니다." << endl;
			break;
		case 4:
			queue.Clear();
			break;
		case 5:
			cout << "검색 데이터: ";
			cin >> x;
			if (queue.Search(x) == -1)
				cout << "\a오류: 검색에 실패했습니다." << endl;
			else
				cout << x << "은(는) 큐 상에 존재합니다." << endl;
			break;
		case 6:
			queue.Print();
			break;
		}
	}

	queue.Terminate();
	return 0;
}