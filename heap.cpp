#include <iostream>

void HeapDown(int* ary, int idx, int maxIdx);
void HeapUp(int* ary, int idx);
void Swap(int& a, int& b);

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, x;
	cin >> N;
	int* ary = new int[N];
	int size = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (size == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << ary[0] << '\n';
				Swap(ary[0], ary[size - 1]);
				size--;
				HeapDown(ary, 0, size - 1);
			}
		}
		else
		{
			ary[size++] = x;
			HeapUp(ary, size - 1);
		}
	}

	delete[] ary;

	return 0;
}

void HeapDown(int* ary, int idx, int maxIdx)
{
	while (true) 
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int lowest = idx;

		if (left <= maxIdx) 
		{
			if (ary[left] < ary[lowest])
				lowest = left;
		}

		if (right <= maxIdx) 
		{
			if (ary[right] < ary[lowest])
				lowest = right;
		}

		if (lowest != idx) 
		{
			Swap(ary[idx], ary[lowest]);
			idx = lowest;
		}
		else 
		{
			break;
		}
	}
}

void HeapUp(int* ary, int idx)
{
	while (idx > 0 && ary[(idx - 1) / 2] > ary[idx])
	{
		Swap(ary[(idx - 1) / 2], ary[idx]);
		idx = (idx - 1) / 2;
	}
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}