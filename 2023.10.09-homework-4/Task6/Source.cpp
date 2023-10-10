#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	int index_max = 0;
	int index_min = 0;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(mas + i);
		if (*(mas + i) >= max)
		{
			max = *(mas + i);
			index_max = i;
		}
		if (*(mas + i) < min)
		{
			min = *(mas + i);
			index_min = i;
		}

	}
	*(mas + index_min) = max;
	*(mas + index_max) = min;
	for (int i = 0; i < n; i++)
	{
		std::cout << *(mas + i) << " ";
	}
	free(mas);
	return EXIT_SUCCESS;

}