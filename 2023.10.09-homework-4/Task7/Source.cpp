#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int k = 0;
	int f = 0;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(mas + i);
		if (*(mas + i) > 0)
		{
			k = k + 1;
		}
	}
	int* mas2 = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < n; ++i)
	{
		if (*(mas + i) > 0)
		{
			*(mas2 + f) = *(mas + i);
			f = f + 1;
		}
	}
	free(mas);
	for (int i = 0; i < k; i++)
	{
		std::cout << *(mas2 + i) << " ";
	}
	free(mas2);
	return EXIT_SUCCESS;

}