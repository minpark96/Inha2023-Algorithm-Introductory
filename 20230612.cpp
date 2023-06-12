#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

void Enque(std::string& temp, Queue& poQue);

int main()
{
	using namespace std;
	ifstream inFile;

	inFile.open("calc.txt");
	if (!inFile.is_open())
	{
		cout << "calc.txt" << " ������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�." << endl;
		exit(EXIT_FAILURE);
	}
	int count = 0;

	string input;
	while (inFile.good())
	{
		count++;
		inFile >> input;
	}
	if (inFile.eof())
		cout << "���� ��" << endl;
	else if (inFile.fail())
		cout << "������ ����ġ" << endl;
	else
		cout << "�� �� ���� ������ �Է��� ����" << endl;
	if (count == 0)
		cout << "������ ����" << endl;
	else
	{
		int max = 64;
		Stack orrStk;
		Stack ordStk;
		Queue poQue;

		if(!orrStk.Initialize(max))
			cout << "\a����: ���� �ʱ�ȭ�� �����߽��ϴ�." << endl;
		if(!ordStk.Initialize(max))
			cout << "\a����: ���� �ʱ�ȭ�� �����߽��ϴ�." << endl;
		if(!poQue.Initialize(max))
			cout << "\a����: ���� �ʱ�ȭ�� �����߽��ϴ�." << endl;

		char ch;
		int idx = 0;
		string temp;
		while (idx < input.size() + 2)
		{
			ch = input[idx];
			if (ch == '*' || ch == '/')
			{
				Enque(temp, poQue);

				if (orrStk.Peek(temp))
				{
					if (temp == "*" || temp == "/")
					{
						if(orrStk.Pop(temp))
						{
							if (!poQue.Enque(temp))
								cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
						}
						else
							cout << "\a����: �˿� �����߽��ϴ�." << endl;
					}
				}
				else
				{
					cout << "\a����: ���� ��ũ�� �����߽��ϴ�." << endl;
				}

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
				temp.clear();
			}
			else if (ch == '+' || ch == '-')
			{
				Enque(temp, poQue);

				if (orrStk.Peek(temp))
				{
					if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
					{
						if (orrStk.Pop(temp))
						{
							if (!poQue.Enque(temp))
								cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
						}
						else
							cout << "\a����: �˿� �����߽��ϴ�." << endl;
					}
				}
				else
				{
					cout << '?' << temp << endl;
					cout << "\a����: ���� ��ũ�� �����߽��ϴ�." << endl;
				}

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
				temp.clear();
			}
			else if (ch == ')')
			{
				Enque(temp, poQue);

				if (orrStk.Pop(temp))
				{
					if (!poQue.Enque(temp))
						cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
					
					if(!orrStk.Pop(temp))
						cout << "\a����: �˿� �����߽��ϴ�." << endl;
				}
				else
					cout << "\a����: ���� �˿� �����߽��ϴ�." << endl;

				temp.clear();
			}
			else if (ch == '(')
			{
				Enque(temp, poQue);

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
				temp.clear();
			}
			else
				temp += ch;
			idx++;
		}
		
		while (!poQue.IsEmpty())
		{
			string temp;
			if (poQue.Peek(temp))
			{
				if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
				{
					if (!poQue.Deque(temp))
						cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
					string pop;
					double ord1, ord2, res;
					if (ordStk.Pop(pop))
						ord2 = stod(pop);
					else
						cout << "\a����: �˿� �����߽��ϴ�." << endl;
					if (ordStk.Pop(pop))
						ord1 = stod(pop);
					else
						cout << "\a����: �˿� �����߽��ϴ�." << endl;

					if (temp == "*")
						res = ord1 * ord2;
					else if (temp == "/")
						res = ord1 / ord2;
					else if (temp == "+")
						res = ord1 + ord2;
					else
						res = ord1 - ord2;

					temp = to_string(res);

					if (!ordStk.Push(temp))
						cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
				}
				else
				{
					if(!poQue.Deque(temp))
						cout << "\a����: ��ť�� �����߽��ϴ�." << endl;
					if(!ordStk.Push(temp))
						cout << "\a����: Ǫ�ÿ� �����߽��ϴ�." << endl;
				}
			}
			else
				cout << "\a����: ť ��ũ�� �����߽��ϴ�." << endl;
		}

		string res;
		if (!ordStk.Pop(res))
			cout << "\a����: �˿� �����߽��ϴ�." << endl;
		cout << "result: " << res << endl;
	}
	inFile.close();

	return 0;
}

void Enque(std::string& temp, Queue& poQue)
{
	if (!temp.empty())
	{
		if (!poQue.Enque(temp))
			std::cout << "\a����: ��ť�� �����߽��ϴ�." << std::endl;
	}
}