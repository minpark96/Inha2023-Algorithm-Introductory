#include <iostream>

void MergeSort(int* ary, int left, int right);
void Merge(int* ary, int left, int mid, int right);
using namespace std;

int main()
{
	int N, x;
	cin >> N;
	int* ary = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		ary[i] = x;
	}

	MergeSort(ary, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << ary[i] << "\n";
	}

	delete[] ary;

	return 0;
}

void MergeSort(int* ary, int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;

		MergeSort(ary, left, mid);
		MergeSort(ary, mid + 1, right);

		Merge(ary, left, mid, right);
	}
}

void Merge(int* ary, int left, int mid, int right)
{
	int len = right - left + 1;
	int* tmp = new int[len];

	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		if (ary[i] > ary[j])
			tmp[k++] = ary[j++];
		else
			tmp[k++] = ary[i++];
	}

	while (i <= mid)
	{
		tmp[k++] = ary[i++];
	}

	while (j <= right)
	{
		tmp[k++] = ary[j++];
	}

	for (int m = left, n = 0; n < len; m++, n++)
	{
		ary[m] = tmp[n];
	}

	delete[] tmp;
}