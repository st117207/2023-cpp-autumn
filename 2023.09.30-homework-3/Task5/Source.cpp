#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long st = 1;
	long long g = 0;
	long long c = 0;
	long long itog = 0;
	long long k = 0;
	long long count = 0;
	std::cin >> k;
	for (int i = 1; i <= k; i++)
	{
		itog = 0;
		st = 1;
		g = i;
		while (g > 0)
		{
			g = g / 10;
			st = st * 10;
		}
		st = st / 10;
		g = i;
		while (g != 0)
		{
			c = g % 10;
			g = g / 10;
			itog = itog + c * st;
			st = st / 10;
		}
		if (itog == i)
		{
			count = count + 1;
		}
	}
	std::cout << count;
	return EXIT_SUCCESS;
}
