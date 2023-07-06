#include <iostream>

#define SIZE 10
#define MAX 10

void CountingSort(int* ary, int len);

using namespace std;

int main()
{
	int* ary = new int[SIZE];
	int v;
	int size = 0;

	cout << "숫자 입력(종료 시 -1): ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> v;
		if (v < 0)
			break;
		ary[i] = v;
		size++;
	}

	CountingSort(ary, size);

	for (int i = 0; i < size; i++)
	{
		cout << ary[i] << " ";
	}
	cout << '\n';
	delete[] ary;

	return 0;
}

void CountingSort(int* ary, int len)
{
	int* counting = new int[MAX] {0};

	for (int i = 0; i < len; i++)
	{
		counting[ary[i] - 1]++;
	}

	int j = 0;
	int k = 0;

	while (k < len)
	{
		if (counting[j] != 0)
		{
			ary[k++] = j + 1;
			counting[j]--;
		}
		else
		{
			j++;
		}
	}

	delete[] counting;
}