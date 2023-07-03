#include <iostream>
#define SIZE 20

void BubbleSort(int* ary, int& len);
void SimpleSelectionSort(int* ary, int& len);
void SimpleInsertionSort(int* ary, int& len);
void ShellSort(int* ary, int& len);
void QuickSort(int* ary, int pl, int pr);
void MergeSort(int* ary, int left, int right);
void Merge(int* ary, int left, int mid, int right);
void Swap(int& a, int& b);

int numCompBubble, numSwapBubble,
numCompSelection, numSwapSelection,
numCompInsertion, numSwapInsertion,
numCompShell, numSwapShell,
numCompQuick, numSwapQuick,
numCompMerge, numSwapMerge;
using namespace std;

int main()
{
	int* ary1 = new int[SIZE];
	int* ary2 = new int[SIZE];
	int* ary3 = new int[SIZE];
	int* ary4 = new int[SIZE];
	int* ary5 = new int[SIZE];
	int* ary6 = new int[SIZE];
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
		ary4[i] = ary1[i];
		ary5[i] = ary1[i];
		ary6[i] = ary1[i];
	}

	cout << "Bubble Sort" << endl;
	BubbleSort(ary1, size);	
	for (int i = 0; i < size; i++)
	{
		cout << ary1[i] << " ";
	}
	cout << endl;
	cout << "Bubble Sort - 비교: " << numCompBubble << "회, 교환: " << numSwapBubble << "회" << endl << endl;


	cout << "Simple Selection Sort" << endl;
	SimpleSelectionSort(ary2, size);	
	for (int i = 0; i < size; i++)
	{
		cout << ary2[i] << " ";
	}
	cout << endl;
	cout << "Simple Selection Sort - 비교: " << numCompSelection << "회, 교환: " << numSwapSelection << "회" << endl << endl;


	cout << "Simple Insertion Sort" << endl;
	SimpleInsertionSort(ary3, size);	
	for (int i = 0; i < size; i++)
	{
		cout << ary3[i] << " ";
	}
	cout << endl;
	cout << "Simple Insertion Sort - 비교: " << numCompInsertion << "회, 교환: " << numSwapInsertion << "회" << endl << endl;


	cout << "Shell Sort" << endl;
	ShellSort(ary4, size);	
	for (int i = 0; i < size; i++)
	{
		cout << ary4[i] << " ";
	}
	cout << endl;
	cout << "Shell Sort - 비교: " << numCompShell << "회, 교환: " << numSwapShell << "회" << endl << endl;


	cout << "Quick Sort" << endl;
	QuickSort(ary5, 0, size - 1);	
	for (int i = 0; i < size; i++)
	{
		cout << ary5[i] << " ";
	}
	cout << endl;
	cout << "Quick Sort - 비교: " << numCompQuick << "회, 교환: " << numSwapQuick << "회" << endl << endl;


	cout << "Merge Sort" << endl;
	MergeSort(ary6, 0, size - 1);	
	for (int i = 0; i < size; i++)
	{
		cout << ary6[i] << " ";
	}
	cout << endl;
	cout << "Merge Sort - 비교: " << numCompMerge << "회, 교환: " << numSwapMerge << "회" << endl;


	delete[] ary1, ary2, ary3, ary4, ary5, ary6;

	return 0;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* ary, int& len)
{
	int prev = len - 1;
	for (int i = len - 1; i > 0; i--)
	{
		int count = 0;
		int next;

		for (int j = 0; j < prev; j++)
		{
			++numCompBubble;
			if (ary[j + 1] < ary[j])
			{
				Swap(ary[j], ary[j + 1]);
				count++;
				next = j;
				++numSwapBubble;
			}
		}

		if (count == 0)
			break;
		prev = next;
	}
}

void SimpleSelectionSort(int* ary, int& len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < len; j++)
		{
			++numCompSelection;
			if (ary[minIdx] > ary[j])
			{
				minIdx = j;
			}
		}

		if(minIdx != i)
		{
			Swap(ary[minIdx], ary[i]);
			++numSwapSelection;
		}
	}
}

void SimpleInsertionSort(int* ary, int& len)
{
	for (int i = 1; i < len; i++)
	{
		int temp = ary[i];
		int j = i;

		while (j > 0) 
		{
			++numCompInsertion;

			if (temp < ary[j - 1])
			{
				ary[j] = ary[j - 1];
				j--;

				++numSwapInsertion;
			}
			else
			{
				break;
			}
		}

		ary[j] = temp;
	}
}

void ShellSort(int* ary, int& len)
{
	int gap;
	for (gap = 1; gap < len; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
		for (int i = gap; i < len; i++)
		{
			int temp = ary[i];
			int j;
			for (j = i - gap; j >= 0; j -= gap)
			{
				++numCompShell;
				if (ary[j] > temp)
				{
					++numSwapShell;
					ary[j + gap] = ary[j];
				}
				else
					break;
			}
			ary[j + gap] = temp;
		}
}

void QuickSort(int* ary, int left, int right)
{
	int x = ary[(left + right) / 2];
	int pl = left;
	int pr = right;

	while (pl <= pr)
	{
		while (ary[pl] < x)
		{
			++numCompQuick;
			pl++;
		}
		++numCompQuick;

		while (ary[pr] > x)
		{
			++numCompQuick;
			pr--;
		}
		++numCompQuick;

		if (pl <= pr)
		{
			++numSwapQuick;
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
	int tmp[SIZE];

	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		++numCompMerge;
		if (ary[i] > ary[j])
			tmp[k++] = ary[j++];
		else
			tmp[k++] = ary[i++];
	}

	while (i <= mid)
	{
		tmp[k++] = ary[i++];
		++numSwapMerge;
	}

	while (j <= right)
	{
		tmp[k++] = ary[j++];
		++numSwapMerge;
	}

	for (int m = left, n = 0; n < len; m++, n++)
	{
		ary[m] = tmp[n];
	}
}