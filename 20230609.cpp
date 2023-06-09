#include <iostream>
#include <string>
using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string& s);

int main()
{
	int num = 12345;
	string str = "abcd";

	reverseDisplay(num);
	reverseDisplay(str);

	return 0;
}

void reverseDisplay(int value)
{
	if (value > 0)
	{
		cout << value % 10;
		reverseDisplay(value / 10);
	}
	else
		cout << endl;
}

void reverseDisplay(const string &s)
{
	if (!s.empty())
	{
		cout << s[s.size() - 1];
		reverseDisplay(s.substr(0, s.size() - 1));
	}
	else
		cout << endl;
}