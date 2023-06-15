#include <iostream>

void Hanoi(int& num, const int& dest);

int main()
{
	using namespace std;
	int num;
	cout << "¸î ´Ü?: ";
	cin >> num;

	return 0;
}

void Hanoi(int& num, const int& dest)
{
	for (int i = num - 1; i >= 0; i--)
	{
		std::cout << std::endl;
	}

}