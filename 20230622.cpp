#include <iostream>
#define SIZE 10

void SimpleInsertionSort(int* ary, int& len);
void PrintNum(int* ary, int& len);
void PrintPos(int* ary, int& len, int& tar, int& sel);

using namespace std;

int main()
{
	int* ary = new int[SIZE];
	int v;
	int size = 0;

	cout << "���� �Է�(���� �� -1): ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> v;
		if (v < 0)
			break;
		ary[i] = v;
		size++;
	}

	SimpleInsertionSort(ary, size);

	delete[] ary;

	return 0;
}

void SimpleInsertionSort(int* ary, int& len)
{
	cout << "SISort" << endl;
	int echg = 0, comp = 0;
	for (int i = 1; i < len; i++)
	{
		PrintNum(ary, len);
		int temp = ary[i];
		int j;
		for (j = i; j > 0; j--)
		{
			comp++;
			if (temp < ary[j - 1])
			{
				echg++;
				ary[j] = ary[j - 1];
			}
			else
				break;
		}
		PrintPos(ary, len, j, i);
		echg++;
		ary[j] = temp;
	}
	PrintNum(ary, len);
	cout << "SISort - ��: " << comp << "ȸ, ��ȯ: " << echg << "ȸ" << endl;
}

void PrintNum(int* ary, int& len)
{
	for (int i = 0; i < len; i++)
	{
		cout << " ";
		cout << ary[i];
	}
	cout << endl;
}

void PrintPos(int* ary, int& len, int& tar, int& temp)
{
	for (int i = 0; i < len; i++)
	{

		if (i < tar)
			cout << "  ";
		else if (tar == temp)
		{
			cout << " ";
			cout << "+";
			break;
		}
		else if (i == tar)
		{
			cout << "^";
			cout << "-";
		}
		else if (i == temp)
		{
			cout << "-";
			cout << "+";
			break;
		}
		else
			cout << "--";
	}
	cout << endl;
}