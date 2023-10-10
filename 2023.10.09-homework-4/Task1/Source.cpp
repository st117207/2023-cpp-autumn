#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	int k = 0;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(mas + i);
		if ((*(mas + i)) > 0)
		{
			k = k + 1;
		}
	}
	free(mas);
	std::cout << k;
	return EXIT_SUCCESS;

}