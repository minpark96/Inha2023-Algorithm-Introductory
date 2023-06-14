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
//	cout << "bsearch 함수를 사용하여 검색" << endl;
//	cout << "요소 개수: ";
//	cin >> nx;
//	int* x = new int[nx];
//
//	cout << "오름차순으로 입력하세요." << endl;
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
//	cout << "검색값: ";
//	cin >> ky;
//	int* p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
//	if (p == NULL)
//		cout << "검색에 실패했습니다." << endl;
//	else
//		cout << ky << "은(는) x[" << (int)(p - x) << "]에 있습니다." << endl;
//	delete[] x;
//	return 0;
//}

#include <iostream>
#include <vector>

int int_cmp(const int* a, const int* b);
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));

int main()
{ 
	using namespace std;

	int nx, ky;
	cout << "bsearchx 함수를 사용하여 검색" << endl;
	cout << "요소 개수: ";
	cin >> nx;
	vector<int> x(nx);

	cout << "오름차순으로 입력하세요." << endl;
	cout << "x[0]: ";
	cin >> x[0];
	for (int i = 1; i < nx; i++)
	{
		do
		{
			cout << "x[" << i << "]: ";
			cin >> x[i];
		} while (x[i] < x[i - 1]);
	}

	cout << "검색값: ";
	cin >> ky;
	int* p = (int*)bsearchx(&ky, &x[0], nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if (p == NULL)
		cout << "검색에 실패했습니다." << endl;
	else
		cout << ky << "은(는) x[" << (int)(p - (int*)&x[0]) << "]에 있습니다." << endl;

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

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	size_t start = 0;
	size_t end = nmemb - 1;
	size_t idx;
	char* x = (char*)base;
	if (nmemb > 0)
	{
		do
		{
			idx = (start + end) / 2;
			int comp = compar(key, x + idx * size);
			if (comp == 0)
			{
				while (idx > 0)
				{
					comp = compar(key, x + (idx - 1) * size);
					if (comp == 0)
						idx--;
					else
						return x + idx * size;
				}
				return x;
			}
			else if (comp > 0)
				start = idx + 1;
			else
				end = idx - 1;
		} while (start <= end);
	}

	return NULL;
}
