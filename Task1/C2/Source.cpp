#include <iostream>

void change1(int*& a, int k);
void sort(int*& a, int n);
int count(int*& a, int k);
void hanoi(int*& a, int k, int from, int to);
void change2(int*& a, int h, int k);


int main(int argc, char* argv[])
{
	int* mas = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; ++i)
	{
		mas[i] = 0;
	}
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> mas[i];
	}
	sort(mas, n);
	return EXIT_SUCCESS;
}
void sort(int*& a, int n)
{
	int temp = 0;
	int* mas1 = (int*)malloc(sizeof(int) * 10);
	int* mas3 = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; ++i)
	{
		mas1[i] = 0;
		mas3[i] = 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		mas1[i] = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if ((mas1[i] < mas3[0]) || (mas3[0] == 0))
		{
			change1(mas3, mas1[i]);
			std::cout << mas1[i] << " " << "1 " << "3" << std::endl;
		}
		else
		{
			temp = count(mas3, mas1[i]);
			change2(mas3, temp, mas1[i]);
			hanoi(mas3, temp, 3, 1);
			hanoi(mas3, temp + 1, 1, 3);
		}
	}

}
int count(int*& a, int k)
{
	int f = 0;
	for (int i = 0; i < 9; ++i)
	{
		if ((a[i] < k) && (a[i + 1] > k))
		{
			return i;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if (a[i] > 0)
		{
			f = f + 1;
		}
	}
	return f - 1;
}
void change2(int*& a, int h, int k)
{
	for (int i = 10; i > h; --i)
	{
		a[i] = a[i - 1];
	}
	a[h + 1] = k;
}
void change1(int*& a, int k)
{
	for (int i = 10; i > 0; --i)
	{
		a[i] = a[i - 1];
	}
	a[0] = k;
}
void hanoi(int*& a, int k, int from, int to)
{
	if (k >= 0)
	{
		int res = 6 - from - to;
		hanoi(a, k - 1, from, res);
		std::cout << a[k] << " " << from << " " << to << std::endl;
		hanoi(a, k - 1, res, to);
	}
	else
	{
		return;
	}
}
