#include <iostream>
#include "int_stack.h"
#include "queue.h"

void Hanoi(IntStack& t1, IntStack& t2, IntStack& t3, int& num, const int& dest);

int main()
{
	using namespace std;
	int num;
	cout << "몇 단?: ";
	cin >> num;
	IntStack t1, t2, t3;

	if (!t1.Initialize(num))
		cout << "/a오류: 스택 초기화 실패" << endl;
	if (!t2.Initialize(num))
		cout << "/a오류: 스택 초기화 실패" << endl;
	if (!t3.Initialize(num))
		cout << "/a오류: 스택 초기화 실패" << endl;

	Hanoi(t1, t2, t3, num, 3);

	return 0;
}

void Hanoi(IntStack& t1, IntStack& t2, IntStack& t3, int& num, const int& dest)
{
	for (int i = num - 1; i >= 0; i--)
	{
		t1.NewPrint(i);
		t2.NewPrint(i);
		t3.NewPrint(i);
		std::cout << std::endl;
	}

	int n = num - 1;
	if (n == 0)
		return;
	else
	{
		if (dest == 3)
			Hanoi(t1, t2, t3, n, 2);
		else
			Hanoi(t1, t2, t3, n, 3);
	}

	while (true)
	{
		
		int temp;
		if (dest == 3)
		{
			if (n == t3.Size())
				return;
		}
		else
		{
			if (n == t2.Size())
				return;
		}
	}
}