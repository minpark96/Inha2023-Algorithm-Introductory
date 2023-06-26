#include <iostream>
#define SIZE 8
void EightQueen(int(&pos)[SIZE], int(&flagR)[SIZE], 
	int(&flagDR)[SIZE * 2 - 1], int(&flagDL)[SIZE * 2 - 1], int col, int& count);
void Print(int (&pos)[SIZE]);
using namespace std;

int main()
{
	int pos[SIZE] = { 0 };
	int flagR[SIZE] = { 0 };
	int flagDR[SIZE * 2 - 1] = { 0 };
	int flagDL[SIZE * 2 - 1] = { 0 };
	int count = 0;

	EightQueen(pos, flagR, flagDR, flagDL, 0, count);
	cout << "ÀüÃ¼: " << count << "È¸" << endl;
	return 0;
}

void EightQueen(int(&pos)[SIZE], int(&flagR)[SIZE], int(&flagDR)[SIZE * 2 - 1], 
	int(&flagDL)[SIZE * 2 - 1], int col, int& count)
{
	if (col == SIZE)
	{
		Print(pos);
		count++;
		cout << endl;
		return;
	}

	for (int row = 0; row < SIZE; row++)
	{
		if (flagR[row] == 0 && flagDR[SIZE - 1 + row - col] == 0
			&& flagDL[row + col] == 0)
		{
			pos[col] = row;
			flagR[row] = 1;
			flagDR[SIZE - 1 + row - col] = 1;
			flagDL[row + col] = 1;
			EightQueen(pos, flagR, flagDR, flagDL, col + 1, count);
			flagR[row] = 0;
			flagDR[SIZE - 1 + row - col] = 0;
			flagDL[row + col] = 0;
		}
	}
}

void Print(int (&pos)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (pos[i] == j)
				cout << "¡á";
			else
				cout << "¡à";
		}
		cout << endl;
	}
}