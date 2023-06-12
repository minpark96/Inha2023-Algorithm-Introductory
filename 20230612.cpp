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
		cout << "calc.txt" << " 파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
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
		cout << "파일 끝" << endl;
	else if (inFile.fail())
		cout << "데이터 불일치" << endl;
	else
		cout << "알 수 없는 이유로 입력이 종료" << endl;
	if (count == 0)
		cout << "데이터 없음" << endl;
	else
	{
		int max = 64;
		Stack orrStk;
		Stack ordStk;
		Queue poQue;

		if(!orrStk.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;
		if(!ordStk.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;
		if(!poQue.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;

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
								cout << "\a오류: 인큐에 실패했습니다." << endl;
						}
						else
							cout << "\a오류: 팝에 실패했습니다." << endl;
					}
				}
				else
				{
					cout << "\a오류: 스택 피크에 실패했습니다." << endl;
				}

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a오류: 푸시에 실패했습니다." << endl;
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
								cout << "\a오류: 인큐에 실패했습니다." << endl;
						}
						else
							cout << "\a오류: 팝에 실패했습니다." << endl;
					}
				}
				else
				{
					cout << '?' << temp << endl;
					cout << "\a오류: 스택 피크에 실패했습니다." << endl;
				}

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a오류: 푸시에 실패했습니다." << endl;
				temp.clear();
			}
			else if (ch == ')')
			{
				Enque(temp, poQue);

				if (orrStk.Pop(temp))
				{
					if (!poQue.Enque(temp))
						cout << "\a오류: 인큐에 실패했습니다." << endl;
					
					if(!orrStk.Pop(temp))
						cout << "\a오류: 팝에 실패했습니다." << endl;
				}
				else
					cout << "\a오류: 스택 팝에 실패했습니다." << endl;

				temp.clear();
			}
			else if (ch == '(')
			{
				Enque(temp, poQue);

				temp.clear();
				temp += ch;
				if (!orrStk.Push(temp))
					cout << "\a오류: 푸시에 실패했습니다." << endl;
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
						cout << "\a오류: 디큐에 실패했습니다." << endl;
					string pop;
					double ord1, ord2, res;
					if (ordStk.Pop(pop))
						ord2 = stod(pop);
					else
						cout << "\a오류: 팝에 실패했습니다." << endl;
					if (ordStk.Pop(pop))
						ord1 = stod(pop);
					else
						cout << "\a오류: 팝에 실패했습니다." << endl;

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
						cout << "\a오류: 푸시에 실패했습니다." << endl;
				}
				else
				{
					if(!poQue.Deque(temp))
						cout << "\a오류: 디큐에 실패했습니다." << endl;
					if(!ordStk.Push(temp))
						cout << "\a오류: 푸시에 실패했습니다." << endl;
				}
			}
			else
				cout << "\a오류: 큐 피크에 실패했습니다." << endl;
		}

		string res;
		if (!ordStk.Pop(res))
			cout << "\a오류: 팝에 실패했습니다." << endl;
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
			std::cout << "\a오류: 인큐에 실패했습니다." << std::endl;
	}
}