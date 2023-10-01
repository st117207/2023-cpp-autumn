#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long count = 0;
	long long h = 1;
	std::cin >> a;
	while (h * h < a)
	{
		h++;
	}
	for (long long i = 1; i <= h; i++)
	{
		if (a % i == 0)
		{
			count++;
		}
	}
	count = count * 2;
	if (h * h == a)
		count = count - 1;
	std::cout << count;
	return EXIT_SUCCESS;
}


