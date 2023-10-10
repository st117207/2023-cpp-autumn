#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(mas + i);
	}
	for (int i = 0; i < n; ++i)
	{
		if (*(mas + i) % 2 != 0)
		{
			std::cout << *(mas + i) << " ";
		}
	}
	free(mas);
	return EXIT_SUCCESS;

}