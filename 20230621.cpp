#include <iostream>
#include "stopwatch.h"
#define SIZE 10

void SSSortV1(int* ary, int& len);
void SSSortV2(int* ary, int& len);
void BubbleSort(int* ary, int& len);
void Swap(int& a, int& b);
void PrintBubble(int* ary, int& len, int& idx, int flag);
void PrintSS(int* ary, int& len, int& idx, int& min);

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
	BubbleSort(ary1, size);
	sw.stop();
	cout << "Bubble 걸린 시간: " << sw.getElapsedTime() << "msec" << endl << endl;

	sw.start();
	SSSortV1(ary2, size);
	sw.stop();
	cout << "SSS V1 걸린 시간: " << sw.getElapsedTime() << "msec" << endl << endl;

	sw.start();
	SSSortV2(ary3, size);
	sw.stop();
	cout << "SSS V2 걸린 시간: " << sw.getElapsedTime() << "msec" << endl << endl;

	delete[] ary1, ary2, ary3;

	return 0;
}

void SSSortV1(int* ary, int& len)
{
	std::cout << "SSSort V1" << std::endl;
	int min;
	int echg = 0, comp = 0;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
		{
			comp++;
			if (ary[min] > ary[j])
				min = j;
		}
		PrintSS(ary, len, i, min);
		echg++;
		Swap(ary[min], ary[i]);
	}
	PrintSS(ary, len, len, len);
	std::cout << "SSSort V1 - 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void SSSortV2(int* ary, int& len)
{
	std::cout << "SSSort V2" << std::endl;
	int min;
	int echg = 0, comp = 0;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
		{
			comp++;
			if (ary[min] > ary[j])
			{
				PrintSS(ary, len, min, j);
				echg++;
				Swap(ary[min], ary[j]);
			}
		}
	}
	PrintSS(ary, len, len, len);
	std::cout << "SSSort V2 - 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void BubbleSort(int* ary, int& len)
{
	std::cout << "Bubble Sort" << std::endl;
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
				PrintBubble(ary, len, j, 1);
				Swap(ary[j], ary[j + 1]);
				echg++;
				count++;
				next = j;
			}
			else
				PrintBubble(ary, len, j, -1);
		}
		PrintBubble(ary, len, len, 0);
		if (count == 0)
			break;
		prev = next;
	}
	std::cout << "Bubble Sort - 비교: " << comp << "회, 교환: " << echg << std::endl;
}

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void PrintBubble(int* ary, int& len, int& idx, int flag)
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

void PrintSS(int* ary, int& len, int& idx, int& min)
{
	using std::cout;
	using std::endl;

	for (int i = 0; i < len; i++)
	{
		if (i == idx)
			cout << "*";
		else if (i == min)
			cout << "+";
		else
			cout << " ";
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << ary[i];
		cout << " ";
	}
	cout << endl;
}