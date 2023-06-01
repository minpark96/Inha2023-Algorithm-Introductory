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
	
	cout << "데이터 입력: ";
	for (int i = 0; i < SIZE; i++)
		cin >> data[i];

	// 선형
	while (true)
	{
		cout << "검색 데이터: ";
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
				cout << "자료중에 " << target << "가 있습니다." << endl;
				break;
			}
		}
		count++;
		if(i == SIZE)
			cout << "자료중에 " << target << "은 없습니다." << endl;
		
		count++;
		cout << "선형 if 수행 횟수: " << count << endl;
	}

	data.resize(SIZE + 1);

	// 보초법
	while (true)
	{
		cout << "검색 데이터: ";
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
			cout << "자료중에 " << target << "은 없습니다." << endl;
		else
			cout << "자료중에 " << target << "가 있습니다." << endl;

		count++;
		cout << "보초법 if 수행 횟수: " << count << endl;
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