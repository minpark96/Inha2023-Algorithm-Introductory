#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

//int max4(int a, int b, int c, int d);
//
//int main()
//{
//	int a = 9, b = 3, c = 5, d = 2;
//	int max;
//
//	printf("�� ���� a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
//	max = max4(a, b, c, d);
//	printf("�ִ밪�� %d�Դϴ�.\n", max);
//
//	return 0;
//}
//
//int max4(int a, int b, int c, int d)
//{
//	int max = a;
//
//	if (b > max)
//		max = b;
//
//	if (c > max)
//		max = c;
//
//	if (d > max)
//		max = d;
//
//	return max;
//}

int my_med3(int a, int b, int c);
int med3(int a, int b, int c);

int main()
{
	int a, b, c, med;
	printf("a, b, c �Է�\n");
	scanf("%d%d%d", &a, &b, &c);

	clock_t startTime, currentTime;

	startTime = clock();
	for (long long i = 0; i < 1000000000; i++)
	{
		med = my_med3(a, b, c);
	}
	currentTime = clock();
	printf("�߾Ӱ�: %d, med3 �ɸ� �ð�: %dmsec\n", med, currentTime - startTime);

	startTime = clock();
	for (long long i = 0; i < 1000000000; i++)
	{

		med = med3(a, b, c);
	}
	currentTime = clock();
	printf("�߾Ӱ�: %d, my_med3 �ɸ� �ð�: %dmsec\n", med, currentTime - startTime);

	return 0;
}

int my_med3(int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return b;
		else
		{
			if (a > c)
				return c;
			else
				return a;
		}
			
	}
	else
	{
		if (a > c)
			return a;
		else
		{
			if (b > c)
				return c;
			else
				return b;
		}
	}
}

int med3(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))
	{
		return a;
	}
	else if ((a > b && b < b) || (a < b && c > b))
	{
		return b;
	}
		
	return c;
}