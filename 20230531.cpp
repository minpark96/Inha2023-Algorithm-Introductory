//#include <iostream>
//#include <vector>
//
//using namespace std;
//void PrintArray(vector<int>& ary);
//
//int main()
//{
//	vector<int> ary { 5, 10, 73, 2, -5, 42 };
//
//	for (int i = 0; i < ary.size() / 2; i++)
//	{
//		int temp;
//
//		PrintArray(ary);
//
//		cout << endl << "a[" << i << "]�� a[" << ary.size() - i - 1 << "]�� ��ȯ�մϴ�." << endl;
//
//		temp = ary[i];
//		ary[i] = ary[ary.size() - i - 1];
//		ary[ary.size() - i - 1] = temp;
//	}
//
//	PrintArray(ary);
//	cout << endl << "���� ������ �����մϴ�." << endl;
//
//	return 0;
//}
//
//void PrintArray(vector<int>& ary)
//{
//	for (int a : ary)
//		cout << a << ' ';
//}

#include <iostream>
#include <cmath>

using namespace std;
const int MAX_NUM = 1000;
const int ARR_SIZE = 200;
const double NUM_SQRT = sqrt(MAX_NUM);
const int NEW_ARR_SIZE = 50;

int main()
{
	// 1��
	int count = 0;

	for (int i = 2; i <= MAX_NUM; i++)
	{
		for (int j = 2; j < i; j++)
		{
			count++;
			if (i % j == 0)
				break;
		}
	}

	cout << "(1) ������ ���� Ƚ��: " << count << endl;
	
	// 2��
	count = 0;

	for (int i = 3; i <= MAX_NUM; i += 2)
	{
		for (int j = 3; j < i; j += 2)
		{
			count++;
			if (i % j == 0)
				break;
		}
	}

	cout << "(2) ������ ���� Ƚ��: " << count << endl;
	
	// 3��
	count = 0;

	int prime[ARR_SIZE] = { 0 };
	int idx = 0;

	for (int i = 3; i <= MAX_NUM; i += 2)
	{
		bool isPrime = true;
		for (int j = 0; j < idx; j++)
		{
			count++;
			if (i % prime[j] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			prime[idx] = i;
			idx++;
		}
	}

	cout << "(3) ������ ���� Ƚ��: " << count << endl;
	
	// 4��
	count = 0;
	int newPrime[NEW_ARR_SIZE] = { 0 };
	idx = 0;

	for (int i = 3; i <= NUM_SQRT; i += 2)
	{
		bool isPrime = true;
		for (int j = 0; j < idx; j++)
		{
			count++;
			if (i % newPrime[j] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			newPrime[idx] = i;
			idx++;
		}
	}

	int i;
	if ((int)NUM_SQRT % 2 == 0)
		i = (int)NUM_SQRT + 1;
	else
		i = (int)NUM_SQRT + 2;

	for (; i <= MAX_NUM; i += 2)
	{
		for (int j = 0; j < idx; j++)
		{
			count++;
			if (i % newPrime[j] == 0)
				break;
		}
	}

	cout << "(4) ������ ���� Ƚ��: " << count << endl;

	return 0;
}