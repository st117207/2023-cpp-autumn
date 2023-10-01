#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long b = 0;
	long long c = 0;
	long long d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	for (int i = 0; i <= 1000; i++)
	{
		if ((a * i * i * i + b * i * i + c * i + d) == 0)
		{
			std::cout << i << " ";
		}
	}
	return EXIT_SUCCESS;
}


