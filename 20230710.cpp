#include <iostream>
#include <string>

using namespace std;
void KMPMethod(string& str_input, string& str_target);
void BFMethod(string& str_input, string& str_target);
void PrintBF(string& str_input, string& str_target, int& front, int& idx, bool succ);
int kmp_comparison, bf_comparison;

int main()
{
	string str_input;
	string str_target;
	cout << "���ڿ� �Է�: ";
	getline(cin, str_input);
	cout << "ã�� ���ڿ� �Է�: ";
	getline(cin, str_target);

	BFMethod(str_input, str_target);
	cout << "��ü �� Ƚ��: " << bf_comparison << "\n";

	KMPMethod(str_input, str_target);
	cout << "��ü �� Ƚ��: " << kmp_comparison << "\n";

	return 0;
}

void KMPMethod(string& str_input, string& str_target)
{
	int curr_front = 0;
	int tar_idx = 0;
	int* table = new int[str_target.size()] {};

	int cnt = 0;
	for (int i = 0, j = 1; j < str_target.size(); j++)
	{
		if (str_target[i] == str_target[j])
		{
			table[j] = ++cnt;
			i++;
		}
		else
		{
			cnt = 0;
			i = 0;
		}
	}

	int size = str_input.size() - str_target.size() + 1;
	while (curr_front < size)
	{
		kmp_comparison++;
		if (str_input[curr_front + tar_idx] == str_target[tar_idx])
		{
			PrintBF(str_input, str_target, curr_front, tar_idx, true);
			if (tar_idx == str_target.size() - 1)
			{
				cout << "�񱳸� " << kmp_comparison << "ȸ �õ��մϴ�.\n";
				cout << curr_front + 1 << "��°�� ��ġ�մϴ�.\n";
				tar_idx++;
			}
			else
			{
				tar_idx++;
				continue;
			}
		}
		else
			PrintBF(str_input, str_target, curr_front, tar_idx, false);

		if (tar_idx != 0 && table[tar_idx - 1] != 0)
			curr_front += str_target.size() - table[tar_idx - 1] - 1;
		else
			curr_front++;
		tar_idx = 0;
	}
	delete[] table;
}

void BFMethod(string& str_input, string& str_target)
{
	int curr_front = 0;
	int tar_idx = 0;
	int size = str_input.size() - str_target.size() + 1;
	while (curr_front < size)
	{
		bf_comparison++;
		if (str_input[curr_front + tar_idx] == str_target[tar_idx])
		{
			PrintBF(str_input, str_target, curr_front, tar_idx, true);
			if (tar_idx == str_target.size() - 1)
			{
				cout << "�񱳸� " << bf_comparison << "ȸ �õ��մϴ�.\n";
				cout << curr_front + 1 << "��°�� ��ġ�մϴ�.\n";
				tar_idx = 0;
				curr_front++;
			}
			else
			{
				tar_idx++;
			}
		}
		else
		{
			PrintBF(str_input, str_target, curr_front, tar_idx, false);
			tar_idx = 0;
			curr_front++;
		}
	}
}

void PrintBF(string& str_input, string& str_target, int& front, int& idx, bool succ)
{
	if (idx == 0)
	{
		cout << front;
	}
	else
	{
		cout << ' ';
	}

	cout << ' ';
	cout << str_input << '\n';

	for (int i = 0; i < front + idx + 2; i++)
	{
		cout << ' ';
	}

	if (succ)
	{
		cout << "+\n";
	}
	else
	{
		cout << "|\n";
	}

	for (int i = 0; i < front + 2; i++)
	{
		cout << ' ';
	}

	cout << str_target << '\n';
}