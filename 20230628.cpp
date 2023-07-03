#include <iostream>
#define SIZE 20

void BubbleSort(int* ary, int& len);
void SimpleSelectionSort(int* ary, int& len);
void SimpleInsertionSort(int* ary, int& len);
void ShellSort(int* ary, int& len);
void QuickSort(int* ary, int pl, int pr);
void Swap(int& a, int& b);

int echgQuick, compQuick;
using namespace std;

int main()
{
	int* ary1 = new int[SIZE];
	int* ary2 = new int[SIZE];
	int* ary3 = new int[SIZE];
	int* ary4 = new int[SIZE];
	int* ary5 = new int[SIZE];
	int v;
	int size = 0;

	cout << "���� �Է�(���� �� -1): ";
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
		ary4[i] = ary1[i];
		ary5[i] = ary1[i];
	}

	cout << "Bubble Sort" << endl;
	BubbleSort(ary1, size);
	cout << "SSSort" << endl;
	SimpleSelectionSort(ary2, size);
	cout << "SISort" << endl;
	SimpleInsertionSort(ary3, size);
	cout << "ShellSort" << endl;
	ShellSort(ary4, size);
	cout << "QuickSort" << endl;
	QuickSort(ary5, 0, size - 1);
	cout << "QuickSort - ��: " << compQuick << "ȸ, ��ȯ: " << echgQuick << "ȸ" << endl;

	delete[] ary1, ary2, ary3, ary4, ary5;

	return 0;
}

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void BubbleSort(int* ary, int& len)
{
	int echg = 0, comp = 0;
	int prev = len - 1, next;
	for (int i = len - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < prev; j++)
		{
			comp++;
			if (ary[j + 1] < ary[j])
			{
				Swap(ary[j], ary[j + 1]);
				echg++;
				count++;
				next = j;
			}
		}
		if (count == 0)
			break;
		prev = next;
	}
	cout << "Bubble Sort - ��: " << comp << "ȸ, ��ȯ: " << echg << "ȸ" << endl;
}

void SimpleSelectionSort(int* ary, int& len)
{
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
		echg++;
		Swap(ary[min], ary[i]);
	}
	cout << "SSSort - ��: " << comp << "ȸ, ��ȯ: " << echg << "ȸ" << endl;
}

void SimpleInsertionSort(int* ary, int& len)
{
	int echg = 0, comp = 0;
	for (int i = 1; i < len; i++)
	{
		int temp = ary[i];
		int j;
		for (j = i; j > 0; j--)
		{
			comp++;
			if (temp < ary[j - 1])
			{
				ary[j] = ary[j - 1];
			}
			else
				break;
		}
		echg++;
		ary[j] = temp;
	}
	cout << "SISort - ��: " << comp << "ȸ, ��ȯ: " << echg << "ȸ" << endl;
}

void ShellSort(int* ary, int& len)
{
	int echg = 0, comp = 0;

	int num;
	for (num = 1; num < len; num = num * 3 + 1)
		;

	for (; num > 0; num /= 3)
		for (int i = num; i < len; i++)
		{
			int temp = ary[i];
			int j;
			for (j = i - num; j >= 0; j -= num)
			{
				comp++;
				if (ary[j] > temp)
				{
					ary[j + num] = ary[j];
				}
				else
					break;
			}
			echg++;
			ary[j + num] = temp;
		}

	cout << "ShellSort - ��: " << comp << "ȸ, ��ȯ: " << echg << "ȸ" << endl;
}

void QuickSort(int* ary, int pl, int pr)
{
	int x = ary[(pl + pr) / 2];
	int left = pl;
	int right = pr;	
	
	while (pl <= pr)
	{
		while (ary[pl] < x)
		{
			compQuick++;
			pl++;
		}
		compQuick++;

		while(ary[pr] > x)
		{
			compQuick++;
			pr--;
		}
		compQuick++;

		if (pl <= pr)
		{
			echgQuick++;
			Swap(ary[pl], ary[pr]);
			pl++;
			pr--;
		}
	}

	if (pr > left)
		QuickSort(ary, left, pr);

	if (right > pl)
		QuickSort(ary, pl, right);
}
