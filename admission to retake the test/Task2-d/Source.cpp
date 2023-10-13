#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	for (int i = n; i >= 1; --i)
	{
		for (int j = n; j >= 1; --j)
		{
			std::cout << std::max((i + j - 1) % n, i + j - 1) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}