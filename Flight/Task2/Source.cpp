#include <iostream>
#include <cmath>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* reverse_array = (int*)malloc(sizeof(int) * (abs(n) + 1));
	int* direct_array = (int*)malloc(sizeof(int) * (abs(n) + 1));
	if (n > 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			*(reverse_array + i) = n - i;
		}
		for (int i = 1; i <= n; ++i)
		{
			*(direct_array + i) = n - *(reverse_array + i) - 1;
		}
	}
	else
	{
		for (int i = 1; i <= abs(n); ++i)
		{
			*(reverse_array + i) = n + i;
		}
		for (int i = 1; i <= abs(n); ++i)
		{
			*(direct_array + i) = n + abs(*(reverse_array + i)) + 1;
		}
	}
	for (int i = 1; i <= abs(n); ++i)
	{
		std::cout << *(direct_array + i) << " ";
	}
	std::cout << n<<" ";
	for (int i = 1; i <= abs(n); ++i)
	{
		std::cout << *(reverse_array + i) << " ";
	}
	return EXIT_SUCCESS;
}