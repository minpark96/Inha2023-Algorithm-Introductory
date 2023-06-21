#include <iostream>
#include "stopwatch.h"
#define SIZE 10

void BubbleSortV1(int* ary, int& len);
void BubbleSortV2(int* ary, int& len);
void BubbleSortV3(int* ary, int& len);
void Swap(int& a, int& b);
void Print(int* ary, int& len, int& idx, int flag);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	StopWatch sw;
	int* ary1 = new int[SIZE];
	int* ary2 = new int[SIZE];
	int* ary3 = new int[SIZE];
	int v;
	int size = 0;

	cout << "숫자 입력(종료 시 -1): ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> v;
		if (v < 0)
			break;
		ary1[i] = v;
		size++;
	}

	for (int i = 0; i < size; i++)
	{
		ary2[i] = ary1[i];
		ary3[i] = ary1[i];
	}

	sw.start();
	BubbleSortV1(ary1, size);
	sw.stop();
	cout << "V1 걸린 시간: " << sw.getElapsedTime() << "msec" << endl;

	sw.start();
	BubbleSortV2(ary2, size);
	sw.stop();
	cout << "V2 걸린 시간: " << sw.getElapsedTime() << "msec" << endl;

	sw.start();
	BubbleSortV3(ary3, size);
	sw.stop();
	cout << "V3 걸린 시간: " << sw.getElapsedTime() << "msec" << endl;

	delete[] ary1, ary2, ary3;

	return 0;
}

void BubbleSortV1(int* ary, int& len)
{
	std::cout << "버전 1" << std::endl;
	int echg = 0, comp = 0;
	int pass = 1;
	for (int i = len - 1; i > 0; i--, pass++)
	{
		std::cout << "패스" << pass << ":" << std::endl;
		for (int j = 0; j < i; j++)
		{
			comp++;
			if (ary[j + 1] < ary[j])
			{
				Print(ary, len, j, 1);
				Swap(ary[j], ary[j + 1]);
				echg++;
			}
			else
				Print(ary, len, j, -1);
		}
		Print(ary, len, len, 0);
	}
	std::cout << "V1 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void BubbleSortV2(int* ary, int& len)
{
	std::cout << "버전 2" << std::endl;
	int echg = 0, comp = 0;
	int pass = 1;
	for (int i = len - 1; i > 0; i--, pass++)
	{
		std::cout << "패스" << pass << ":" << std::endl;
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			comp++;
			if (ary[j + 1] < ary[j])
			{
				Print(ary, len, j, 1);
				Swap(ary[j], ary[j + 1]);
				echg++;
				count++;
			}
			else
				Print(ary, len, j, -1);
		}
		Print(ary, len, len, 0);
		if (count == 0)
			break;
	}
	std::cout << "V2 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void BubbleSortV3(int* ary, int& len)
{
	std::cout << "버전 3" << std::endl;
	int echg = 0, comp = 0;
	int prev = len - 1, next;
	int pass = 1;
	for (int i = len - 1; i > 0; i--, pass++)
	{
		std::cout << "패스" << pass << ":" << std::endl;
		int count = 0;
		for (int j = 0; j < prev; j++)
		{
			comp++;
			if (ary[j + 1] < ary[j])
			{
				Print(ary, len, j, 1);
				Swap(ary[j], ary[j + 1]);
				echg++;
				count++;
				next = j;
			}
			else
				Print(ary, len, j, -1);
		}
		Print(ary, len, len, 0);
		if (count == 0)
			break;
		prev = next;
	}
	std::cout << "V3 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void Print(int* ary, int& len, int& idx, int flag)
{
	using std::cout;
	using std::endl;
	for (int i = 0; i < len; i++)
	{
		cout << ary[i];
		if (idx == i)
		{
			if (flag == 1)
				cout << " + ";
			else if (flag == -1)
				cout << " - ";
			else
				cout << "   ";
		}
		else
			cout << "   ";
	}
	cout << endl;
}