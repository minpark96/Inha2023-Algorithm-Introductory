#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

void Enque(std::string& temp, Queue& que);
void Deque(std::string& temp, Queue& que);
void DequeAndPush(std::string& temp, Queue& que, Stack& stk);
void Peek(std::string& temp, Stack& stk);
void Peek(std::string& temp, Queue& que);
void Push(std::string& temp, Stack& stk);
void ClearAndPush(std::string& temp, Stack& stk, char& ch);
void Pop(std::string& temp, Stack& stk);
void PopAndEnque(std::string& temp, Stack& stk, Queue& que);
void PopAndStod(std::string& temp, Stack& stk, double& d);

int main()
{
	using namespace std;
	ifstream inFile;
	//inFile.open("calc.txt");
	inFile.open("Calc2.txt");
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
		Stack stkOrr;
		Stack stkOrd;
		Queue quePo;

		if(!stkOrr.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;
		if(!stkOrd.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;
		if(!quePo.Initialize(max))
			cout << "\a오류: 스택 초기화에 실패했습니다." << endl;

		char ch, neg;
		int idx = 0;
		string temp;
		while (true)
		{
			ch = input[idx];
			if (ch == 0)
			{
				while(!stkOrr.IsEmpty())
					PopAndEnque(temp, stkOrr, quePo);
				break;
			}

			if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')')
			{
				if (!temp.empty())
				{
					Enque(temp, quePo);
					if (neg != 0)
					{
						temp.clear();
						temp += neg;
						Enque(temp, quePo);
						neg = 0;
					}
				}
				else
				{
					if (ch == '-')
					{
						Peek(temp, stkOrr);
						if (temp == "(" || temp == "")
						{
							temp.clear();
							temp += to_string(0);
							Enque(temp, quePo);
							temp.clear();
							neg = ch;
							idx++;
							continue;
						}
						temp.clear();
					}
				}

				if (ch == '*' || ch == '/')
				{
					Peek(temp, stkOrr);
					if (temp == "*" || temp == "/")
						PopAndEnque(temp, stkOrr, quePo);
					ClearAndPush(temp, stkOrr, ch);
				}
				else if (ch == '+' || ch == '-')
				{
					Peek(temp, stkOrr);
					if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
						PopAndEnque(temp, stkOrr, quePo);
					ClearAndPush(temp, stkOrr, ch);
				}
				else if (ch == ')')
				{
					Peek(temp, stkOrr);
					if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
						PopAndEnque(temp, stkOrr, quePo);
					Pop(temp, stkOrr);
					temp.clear();
				}
				else
					ClearAndPush(temp, stkOrr, ch);
			}
			else
				temp += ch;
			idx++;
		}
		
		while (!quePo.IsEmpty())
		{
			string temp;
			Peek(temp, quePo);
			if (temp.empty())
				continue;
			else if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
			{
				Deque(temp, quePo);
				string pop;
				double ord1, ord2, res;
				PopAndStod(pop, stkOrd, ord2);
				PopAndStod(pop, stkOrd, ord1);

				if (temp == "*")
					res = ord1 * ord2;
				else if (temp == "/")
					res = ord1 / ord2;
				else if (temp == "+")
					res = ord1 + ord2;
				else
					res = ord1 - ord2;

				temp = to_string(res);
				Push(temp, stkOrd);
			}
			else
				DequeAndPush(temp, quePo, stkOrd);
		}

		string res;
		Pop(res, stkOrd);
		cout << "result: " << res << endl;

		stkOrr.Terminate();
		stkOrd.Terminate();
		quePo.Terminate();
	}
	inFile.close();

	return 0;
}

void Enque(std::string& temp, Queue& que)
{	
	if (!que.Enque(temp))
		std::cout << "\a오류: 인큐에 실패했습니다." << std::endl;
}

void Deque(std::string& temp, Queue& que)
{
	if (!que.Deque(temp))
		std::cout << "\a오류: 디큐에 실패했습니다." << std::endl;
}

void DequeAndPush(std::string& temp, Queue& que, Stack& stk)
{
	if (!que.Deque(temp))
		std::cout << "\a오류: 디큐에 실패했습니다." << std::endl;
	else
		Push(temp, stk);
}

void Peek(std::string& temp, Stack& stk)
{
	if (!stk.Peek(temp))
		std::cout << "\a오류: 스택 피크에 실패했습니다." << std::endl;
}

void Peek(std::string& temp, Queue& que)
{
	if (!que.Peek(temp))
		std::cout << "\a오류: 큐 피크에 실패했습니다." << std::endl;
}

void Push(std::string& temp, Stack& stk)
{
	if (!stk.Push(temp))
		std::cout << "\a오류: 푸시에 실패했습니다." << std::endl;
}

void ClearAndPush(std::string& temp, Stack& stk, char& ch)
{
	temp.clear();
	temp += ch;
	Push(temp, stk);
	temp.clear();
}

void Pop(std::string& temp, Stack& stk)
{
	if (!stk.Pop(temp))
		std::cout << "\a오류: 팝에 실패했습니다." << std::endl;
}

void PopAndEnque(std::string& temp, Stack& stk, Queue& que)
{
	if (!stk.Pop(temp))
		std::cout << "\a오류: 팝에 실패했습니다." << std::endl;
	else
		Enque(temp, que);
}

void PopAndStod(std::string& temp, Stack& stk, double& d)
{
	if (!stk.Pop(temp))
		std::cout << "\a오류: 팝에 실패했습니다." << std::endl;
	else
		d = stod(temp);
}