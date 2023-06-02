#include <iostream>
#include <vector>

#define SIZE 11

void ScannerHeader();
void ScannerBody(int idx, std::vector<int> v);
void ScannerBody(int idx, int start, int end, std::vector<int> v);

int main()
{
	using namespace std;

	vector<int> data(SIZE + 1);
	int target;

	cout << "������ �Է�: ";
	for (int i = 0; i < SIZE; i++)
		cin >> data[i];

	while (true)
	{
		cout << "�˻� ������: ";
		cin >> target;
		if (target == -99)
			break;
		else
			data[SIZE] = target;

		ScannerHeader();
		int start = 0;
		int end = SIZE - 1;
		int count = 0;
		bool isFound = false;
		int idx;
		do
		{
			idx = (start + end) / 2;
			ScannerBody(idx, start, end, data);
			if (target == data[idx])
			{
				count++;
				isFound = true;
				break;
			}
			else if (target > data[idx])
				start = idx + 1;
			else
				end = idx - 1;

			count += 3;
		} while (start <= end);

		if(isFound)
			cout << target << "�� x[" << idx << "]�� �ֽ��ϴ�." << endl;
		else
			cout << "�ڷ��߿� " << target << "�� �����ϴ�." << endl;

		ScannerHeader();
		count = 0;
		int i = 0;
		for (;; i++)
		{
			ScannerBody(i, data);
			count++;
			if (target == data[i])
				break;

		}

		if (i == SIZE)
			cout << "�ڷ��߿� " << target << "�� �����ϴ�." << endl;
		else
			cout << "�ڷ��߿� " << target << "�� �ֽ��ϴ�." << endl;

		count++;
		cout << "���ʹ� if ���� Ƚ��: " << count << endl;
	}

	return 0;
}

void ScannerHeader()
{
	using namespace std;

	cout << "  |";
	for (int i = 0; i < SIZE; i++)
	{
		cout.width(4);
		cout << std::right << i;
	}
	cout << endl << "--+-";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "----";
	}
	cout << endl;
}

void ScannerBody(int idx, std::vector<int> v)
{
	using namespace std;

	if (idx < SIZE)
	{
		cout << "  |   ";
		for (int i = 0; i < idx; i++)
			cout << "    ";
		cout << "*" << endl;
		cout.width(2);
		cout << std::right << idx << "|";
		for (int i = 0; i < SIZE; i++)
		{
			cout.width(4);
			cout << std::right << v[i];
		}
		cout << endl << "  |" << endl;
	}
}

void ScannerBody(int idx, int start, int end, std::vector<int> v)
{
	using namespace std;

	cout << "  |   ";
	for (int i = 0; i < start; i++)
		cout << "   ";
	cout << "<-";
	for (int i = start + 1; i <= idx; i++)
		cout << "   ";
	cout << "+";
	for (int i = idx + 1; i <= end; i++)
		cout << "   ";
	cout << "->" << endl;
	cout.width(2);
	cout << std::right << idx << "|";
	for (int i = 0; i < SIZE; i++)
	{
		cout.width(4);
		cout << std::right << v[i];
	}
	cout << endl << "  |" << endl;
}