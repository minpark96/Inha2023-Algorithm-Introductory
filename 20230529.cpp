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

	cout << "�Է� �����ʹ� �� ���� : ";
	cin >> base;
	cout << "���� �Է��Ͻÿ� : ";
	cin >> numIn;
	cout << "��� �����ʹ� �� ���� : ";
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

	cout << base << "���� " << numIn << "�� " << target << "������ ";
	for (int i = strlen(numOut) - 1; i >= 0; i--)
	{
		cout << numOut[i];
	}
	cout << " �Դϴ�." << endl;

	return 0;
}

int Exponent(int count, int base)
{
	if (count == 0) return 1;
	return base * Exponent(count - 1, base);
}