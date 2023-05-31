#include <iostream>
#include <string>

#define ASCII_0 48
#define ASCII_9 57
#define ASCII_A 65

using namespace std;
int Exponent(int count, int base);

int main()
{
	string numIn; 
	char numOut[100] = { 0 };
	int base, target, decNum = 0;

	cout << "입력 데이터는 몇 진수 : ";
	cin >> base;
	cout << "값을 입력하시오 : ";
	cin >> numIn;
	cout << "출력 데이터는 몇 진수 : ";
	cin >> target;

	for (int i = numIn.size() - 1; i >= 0; i--)
	{
		if (numIn[i] == ASCII_0) continue;
		else
		{
			if (numIn[i] <= ASCII_9)
				decNum += (numIn[i] - ASCII_0) * Exponent(numIn.size() - 1 - i, base);
			else
				decNum += (numIn[i] - ASCII_A + 10) * Exponent(numIn.size() - 1 - i, base);
		}
	}

	for (int i = 0, j = decNum; j > 0; j = j / target, i++)
	{
		if (j % target < 10)
			numOut[i] = j % target + ASCII_0;
		else
			numOut[i] = j % target + ASCII_A - 10;
	}

	cout << base << "진수 " << numIn << "은 " << target << "진수로 ";
	for (int i = strlen(numOut) - 1; i >= 0; i--)
	{
		cout << numOut[i];
	}
	cout << " 입니다." << endl;

	return 0;
}

int Exponent(int count, int base)
{
	if (count == 0) return 1;
	return base * Exponent(count - 1, base);
}