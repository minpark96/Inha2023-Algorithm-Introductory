//#include <iostream>
//
//int int_cmp(const int* a, const int* b)
//{
//	if (*a < *b)
//		return -1;
//	else if (*a > *b)
//		return 1;
//	else
//		return 0;
//}
//
//int main(void)
//{
//	using namespace std;
//	int nx, ky;
//	cout << "bsearch �Լ��� ����Ͽ� �˻�" << endl;
//	cout << "��� ����: ";
//	cin >> nx;
//	int* x = new int[nx];
//
//	cout << "������������ �Է��ϼ���." << endl;
//	cout << "x[0]: ";
//	cin >> x[0];
//	for (int i = 1; i < nx; i++)
//	{
//		do
//		{
//			cout << "x[" << i << "]: ";
//			cin >> x[i];
//		} while (x[i] < x[i - 1]);
//	}
//	cout << "�˻���: ";
//	cin >> ky;
//	int* p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
//	if (p == NULL)
//		cout << "�˻��� �����߽��ϴ�." << endl;
//	else
//		cout << ky << "��(��) x[" << (int)(p - x) << "]�� �ֽ��ϴ�." << endl;
//	delete[] x;
//	return 0;
//}

#include <iostream>
#include <vector>

#define SIZE 11

int int_cmp(const int* a, const int* b);
void ScannerHeader();
void ScannerBody(int idx, std::vector<int> v);
void ScannerBody(int idx, int start, int end, std::vector<int> v);

int main()
{ 
	using namespace std;

	vector<int> data(SIZE + 1);
	int target;

	cout << "������ �Է�: ";
	for (int i = 0; i < SIZE; i++)
		cin >> data[i];

	return 0;
}

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}