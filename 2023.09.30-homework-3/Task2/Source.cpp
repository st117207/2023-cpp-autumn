#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long st = 1;
	long long g = 0;
	long long c = 0;
	long long itog = 0;
	std::cin >> a;
	g = a;
	while (g > 0)
	{
		g = g / 10;
		st = st * 10;

	}
	st = st / 10;
	while (a != 0)
	{
		c = a % 10;
		a = a / 10;
		itog = itog + c * st;
		st = st / 10;
	}
	std::cout << itog;
	return EXIT_SUCCESS;
}