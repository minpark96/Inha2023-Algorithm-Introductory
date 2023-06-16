#include <iostream>
#include <vector>

using namespace std;
void Hanoi(int num, vector<int>& base, vector<int>& pass, vector<int>& dest, vector<int>** pv);
void Print(vector<int>** pv);

static int height;

int main()
{
	cout << "¸î Ãþ?: ";
	cin >> height;

	vector<int> t1, t2, t3;
	vector<int>* pv[3] = { &t1, &t2, &t3 };

	for (int i = height; i > 0; i--)
		t1.push_back(i);
	cout << "=========" << endl;
	Print(pv);
	Hanoi(height, t1, t2, t3, pv);

	return 0;
}

void Hanoi(int num, vector<int>& base, vector<int>& pass, vector<int>& dest, vector<int>** pv)
{
	if (num == 0) return;
	Hanoi(num - 1, base, dest, pass, pv);
	dest.push_back(base.back());
	base.pop_back();
	cout << "=========" << endl;
	Print(pv);
	Hanoi(num - 1, pass, base, dest, pv);
}

void Print(vector<int>** pv)
{
	for (int i = height - 1; i > -1; i--)
	{
		if ((*pv[0]).size() < i + 1 && (*pv[1]).size() < i + 1 && (*pv[2]).size() < i + 1)
			continue;
		else
		{
			for (int j = 0; j < 3; j++)
			{
				if ((*pv[j]).size() < i + 1)
					cout << "   ";
				else
					cout << "[" << (*pv[j])[i] << "]";
			}
		}
		cout << endl;
	}
}