#include <iostream>
#include <vector>

#define SIZE 8

void ScannerHeader();
void ScannerBody(int idx, std::vector<int> v);

int main()
{
	using namespace std;

	vector<int> data(SIZE);
	int target;
	
	cout << "������ �Է�: ";
	for (int i = 0; i < SIZE; i++)
		cin >> data[i];

	// ����
	while (true)
	{
		cout << "�˻� ������: ";
		cin >> target;
		if (target == -99)
			break;
		int count = 0;
		
		ScannerHeader();

		int i = 0;
		for (; i < SIZE; i++)
		{
			ScannerBody(i, data);
			count += 2;
			if (target == data[i])
			{
				cout << "�ڷ��߿� " << target << "�� �ֽ��ϴ�." << endl;
				break;
			}
		}
		count++;
		if(i == SIZE)
			cout << "�ڷ��߿� " << target << "�� �����ϴ�." << endl;
		
		count++;
		cout << "���� if ���� Ƚ��: " << count << endl;
	}

	data.resize(SIZE + 1);

	// ���ʹ�
	while (true)
	{
		cout << "�˻� ������: ";
		cin >> target;
		if (target == -99)
			break;
		else
			data[SIZE] = target;
		
		ScannerHeader();

		int count = 0;
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
		cout << " " << i;
	}
	cout << endl << "--+-";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "--";
	}
	cout << endl;
}

void ScannerBody(int idx, std::vector<int> v)
{
	using namespace std;

	if (idx < SIZE)
	{
		cout << "  | ";
		for (int i = 0; i < idx; i++)
			cout << "  ";
		cout << "*" << endl << " " << idx << "|";
		for (int i = 0; i < SIZE; i++)
			cout << " " << v[i];
		cout << endl << "  |" << endl;
	}
}