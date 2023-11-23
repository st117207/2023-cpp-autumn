#include<iostream>
#include<algorithm>
#include<ctime>

void initRandomArray(int*& a, int len);
void printArray(int* a, int len);
void swap(int& a, int& b);
void mixArray(int* a, int n);
void bubbleSort(int* a, int len);
void selectionSort(int* a, int len);
bool isSorted(int* a, int len);
void monkeySort(int* a, int len);
void insertionSort(int* a, int len);
void gnomeSort(int* a, int len);
void calcSort(int* a, int len);

int main(int argc, char* argv[])
{
	srand(time(0));
	int n = 10;
	int* a = (int*)malloc(sizeof(int) * n);
	initRandomArray(a, n);
	printArray(a, n);
	{
		std::cout << "bubble sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		bubbleSort(a, n);
		printArray(a, n);
	}
	{
		std::cout << "selection sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		selectionSort(a, n);
		printArray(a, n);
	}
	{
		std::cout << "monkey sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		monkeySort(a, n);
		printArray(a, n);
	}
	{
		std::cout << "insertion sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		insertionSort(a, n);
		printArray(a, n);
	}
	{
		std::cout << "gnome sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		gnomeSort(a, n);
		printArray(a, n);
	}
	{
		std::cout << "calc sort" << std::endl;
		mixArray(a, n);
		printArray(a, n);
		calcSort(a, n);
		printArray(a, n);
	}


	return EXIT_SUCCESS;
}

void initRandomArray(int*& a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 10;
	}

}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void mixArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		swap(a[i], a[rand() % n]);
	}
}

void bubbleSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void selectionSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int mInd = i;
		for (int j = i + 1; j < len; ++j)
		{
			mInd = (a[mInd] <= a[j] ? mInd : j);
		}
		swap(a[i], a[mInd]);
	}
}

bool isSorted(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void monkeySort(int* a, int len)
{
	while (!isSorted(a, len))
	{
		mixArray(a, len);
	}
}

void insertionSort(int* a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int t = i;
		while (t > 0 && a[t] < a[t - 1])
		{
			swap(a[t], a[t - 1]);
			--t;
		}
	}
}

void gnomeSort(int* a, int len)
{
	int i = 0;
	int j = 0;
	i = 1;
	j = 2;
	while (i < len)
	{
		if (a[i] > a[i - 1])
		{
			i = j;
			j = j + 1;
		}
		else
		{
			swap(a[i], a[i - 1]);
			i = i - 1;
			if (i == 0)
			{
				i = j;
				j = j + 1;
			}
		}
	}
}

void calcSort(int* a, int len)
{
	int mas[10]{ 0 };

	for (int i = 0; i < len; i++)
	{
		mas[a[i]] = mas[a[i]] + 1;
	}
	int e = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < mas[i]; ++j)
		{
			a[e] = i;
			e = e + 1;
		}
	}
}