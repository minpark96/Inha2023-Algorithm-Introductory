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

	for (int i = 0; i < SIZE; i++)
	{
		pos[col] = i;
		if (flagR[i] == 0 && flagDR[SIZE - 1 - col + i] == 0 
			&& flagDL[2 * SIZE - 2 - i - col] == 0)
		{
			flagR[i] = 1;
			flagDR[SIZE - 1 - col + i] = 1;
			flagDL[2 * SIZE - 2 - i - col] = 1;
			EightQueen(pos, flagR, flagDR, flagDL, col + 1, count);
			flagR[i] = 0;
			flagDR[SIZE - 1 - col + i] = 0;
			flagDL[2 * SIZE - 2 - i - col] = 0;
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