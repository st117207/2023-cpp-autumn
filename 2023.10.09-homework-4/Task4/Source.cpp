#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int max = INT_MIN;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{

		std::cin >> *(mas + i);
		if (*(mas + i) > max)
		{
			max = *(mas + i);
		}
	}
	free(mas);
	std::cout << max;
	return EXIT_SUCCESS;

}