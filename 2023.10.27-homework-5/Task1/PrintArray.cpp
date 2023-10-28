#include "Function.h"
#include<iostream>

int PrintArray(int* a, int length)
{
	if (a == nullptr)
	{
		std::cout << "Массив пустой";
	}
	else
	{
		for (int i = 0; i < length; ++i)
		{
			std::cout << a[i] << " ";
		}
		return 1;
	}
	std::cout << std::endl;
}
