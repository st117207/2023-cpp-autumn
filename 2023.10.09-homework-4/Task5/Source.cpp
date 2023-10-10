#include <iostream>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* mas = (int*)malloc(sizeof(int) * n);
	int* mas2 = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(mas + i);
		*(mas2 + (n - 1 - i)) = *(mas + i);
	}
	free(mas);
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(mas2 + i) << " ";

	}
	free(mas2);
	return EXIT_SUCCESS;

}