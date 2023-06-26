#include <iostream>
#define SIZE 10

void SSSort(int* ary, int& len);
void SISort(int* ary, int& len);
void ShellSort(int* ary, int& len);
void BubbleSort(int* ary, int& len);
void Swap(int& a, int& b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int* ary1 = new int[SIZE];
	int* ary2 = new int[SIZE];
	int* ary3 = new int[SIZE];
	int* ary4 = new int[SIZE];
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


	BubbleSort(ary1, size);

	SSSort(ary2, size);

	SISort(ary3, size);

	ShellSort(ary4, size);

	delete[] ary1, ary2, ary3;

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
	cout << "Bubble Sort" << endl;
	int echg = 0, comp = 0;
	int prev = len - 1, next;
	int pass = 1;
	for (int i = len - 1; i > 0; i--, pass++)
	{
		cout << "패스" << pass << ":" << endl;
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
	cout << "Bubble Sort - 비교: " << comp << "회, 교환: " << echg << endl;
}

void SSSort(int* ary, int& len)
{
	cout << "SSSort" << endl;
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
	cout << "SSSort V1 - 비교: " << comp << "회, 교환: " << echg << endl;
}

void SISort(int* ary, int& len)
{
	cout << "SISort" << endl;
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
				echg++;
				ary[j] = ary[j - 1];
			}
			else
				break;
		}
		echg++;
		ary[j] = temp;
	}
	cout << "SISort - 비교: " << comp << "회, 교환: " << echg << "회" << endl;
}

void ShellSort(int* ary, int& len)
{

	return;
}