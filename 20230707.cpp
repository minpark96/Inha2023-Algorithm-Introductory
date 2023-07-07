#include <iostream>
#include <string>

using namespace std;
void BFMethod(string& str_input, string& str_target);
void PrintBF(string& str_input, string& str_target, int& front, int& idx, bool succ);
int comparison;

int main()
{
	string str_input;
	string str_target;
	cout << "���ڿ� �Է�: ";
	getline(cin, str_input);
	cout << "ã�� ���ڿ� �Է�: ";
	getline(cin, str_target);
	
	BFMethod(str_input, str_target);
	cout << "��ü �� Ƚ��: " << comparison << "\n";

	return 0;
}

void BFMethod(string& str_input, string& str_target)
{
	int curr_front = 0;
	int tar_idx = 0;
	int size = str_input.size() - str_target.size() + 1;
	while(curr_front < size)
	{
		comparison++;
		if (str_input[curr_front + tar_idx] == str_target[tar_idx])
		{
			PrintBF(str_input, str_target, curr_front, tar_idx, true);
			if (tar_idx == 2)
			{
				cout << "�񱳸� " << comparison << "ȸ �õ��մϴ�.\n";
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