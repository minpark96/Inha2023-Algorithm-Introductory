#include <iostream>

#define SIZE 8
void EightQueen(int* pos, int* flagR, int* flagD1, int* flagD2, int& num);

int main()
{
	int pos[SIZE] = { 0 };
	int flagR[SIZE] = { 0 };
	int flagD1[SIZE * 2 - 1] = { 0 };
	int flagD2[SIZE * 2 - 1] = { 0 };

	EightQueen(pos, flagR, flagD1, flagD2, 0);

	return 0;
}



void EightQueen(int* pos, int* flagR, int* flagD1, int* flagD2, int num)
{
	if (num == SIZE)
		return;

	for (int i = 0; i < SIZE; i++)
	{
		if (flagR[i] == 0 && flagD1[SIZE - 1 - num + i] == 0 && flagD2[SIZE - i - num] == 0)
		{
			pos[num] = i;
			flagR[i] = 1;
			flagD1[SIZE - 1 - num + i] = 1;
			flagD2[SIZE - i - num] = 1;
			EightQueen(pos, flagR, flagD1, flagD2, num + 1);
		}
		else
			continue;
	}




}