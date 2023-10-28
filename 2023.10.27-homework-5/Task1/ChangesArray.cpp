#include "Function.h"
#include<iostream>
#include <ctime>
int ExpandArray(int*& a, int& length, int n)
{
	int* b = new int[length + n] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < length; ++i)
		{
			b[i] = a[i];
		}
		delete[] a;
	}
	a = b;
	length = length + n;
	return 1;
}

int AddElement(int*& a, int& length, int element)
{
	ExpandArray(a, length, 1);
	a[length - 1] = element;
	return 1;
}

int ReverseArray(int* a, int length)
{
	if (a != nullptr)
	{
		int temp = 0;
		for (int i = 0; i < (length / 2) + 1; ++i)
		{
			temp = a[length - i - 1];
			a[length - i - 1] = a[i];
			a[i] = temp;
		}
		return 1;
	}

}

int DeleteElement(int*& a, int& length, int index)
{
	if (a != nullptr)
	{
		if (length != 1)
		{
			int k = 0;
			int* b = new int[length - 1] { 0 };
			for (int i = 0; i < length; ++i)
			{
				if (i != index)
				{
					b[k] = a[i];
					k = k + 1;
				}
			}
			delete[] a;
			a = b;
		}
		else
		{
			int* b = nullptr;
			delete[] a;
			a = b;
		}
		--length;
		return index;
	}
}

int SortArray(int* a, int length)
{
	if (a != nullptr)
	{
		for (int i = 1; i < length; ++i)
		{
			for (int j = 0; j < length - i; ++j)
			{
				if (a[j] > a[j + 1])
				{
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
		return 1;
	}
}

int SearchIndexFirstMaxElement(int* a, int length)
{
	int index_max = 0;
	int max = INT_MIN;
	if (a != nullptr)
	{
		int index_max = 0;
		int max = INT_MIN;
		for (int i = 0; i < length; ++i)
		{
			if (a[i] > max)
			{
				index_max = i;
				max = a[i];
			}
		}
		return index_max;
	}
}

int SearchIndexLastMinElement(int* a, int length)
{
	if (a != nullptr)
	{
		int min = INT_MAX;
		int index_min = 0;
		for (int i = 0; i < length; ++i)
		{
			if (a[i] <= min)
			{
				index_min = i;
				min = a[i];
			}
		}
		return index_min;
	}
}

int ChangeElements(int* a, int length)
{
	if (a != nullptr)
	{
		int index_min = 0;
		int index_max = 0;
		int temp = 0;
		index_min = SearchIndexLastMinElement(a, length);
		index_max = SearchIndexFirstMaxElement(a, length);
		temp = a[index_min];
		a[index_min] = a[index_max];
		a[index_max] = temp;
		return 1;
	}
}

int DeleteDuplicateElements(int*& a, int& length)
{
	int* b = new int[length] { 0 };
	int k = 0;
	if (a != nullptr)
	{
		for (int i = 0; i < length; ++i)
		{
			bool indicate = true;
			for (int j = 0; j < i; ++j)
			{
				if (a[i] == a[j])
				{
					indicate = false;
				}
			}
			if (indicate == true)
			{
				b[k] = a[i];
				k = k + 1;
			}
		}
		int* c = new int[k] { 0 };
		for (int i = 0; i < k; i++)
		{
			c[i] = b[i];
		}
		delete[] b;
		delete[] a;
		a = c;
		length = k;
		return 1;
	}
}

int AddRandomizeElements(int*& a, int& length, int n)
{
	ExpandArray(a, length, n);
	srand(time(0));
	for (int i = length - n; i < length; ++i)
	{
		a[i] = rand();
	}
	return 1;
}