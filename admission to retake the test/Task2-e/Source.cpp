#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cout << (n + 1) / 2 - std::min(abs((n + 1) / 2 - j), abs((n + 1) / 2 - i)) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}