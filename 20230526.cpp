#include <iostream>

//using namespace std;
//
//int gaussSummation(int num);
//int sumof(int a, int b);
//
//int main()
//{
//	int num = 10, sum1, sum2;
//	sum1 = gaussSummation(num);
//
//	cout << "���콺 ��: " << sum1 << endl;
//
//	int a = 8, b = 8;
//	sum2 = sumof(a, b);
//	cout << "�� ���� ���� ��� ���� ��: " << sum2 << endl;
//}
//
//int gaussSummation(int num)
//{
//	return (num + 1) * num / 2;
//}
//
//int sumof(int a, int b)
//{
//	if (a > b)
//	{
//		return (a + b) * (a - b) / 2 + (a + b) / 2 + (a + b) % 2;
//	}
//	else
//	{
//		return (b + a) * (b - a) / 2 + (b + a) / 2 + (b + a) % 2;
//	}
//}

using namespace std;

int main()
{
	int num, row = 1, col = 0;
	cout << "�ܼ� �Է�: ";
	cin >> num;

	for (int i = 0; i < num * 2 - 1; i++)
	{
		for (int j = 0; j < num * 2 - 1; j++)
		{
			if (j < col || j >= num * 2 - 1 - col)
			{
				cout << " ";
			}
			else
			{
				if (row > num)
					cout << num * 2 - row;
				else
					cout << row;
			}
		}

		if (row >= num)
			col--;
		else
			col++;

		row++;
		cout << endl;
	}

	return 0;
}