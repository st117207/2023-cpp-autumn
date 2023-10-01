#include <iostream>

int main(int argc, char* argv[])
{
	long long n = 0;
	long long itog = 1;
	long long st = 0;
	std::cin >> n;
	while (itog < n)
	{
		itog = itog * 2;
		st = st + 1;
	}
	std::cout << st;
	return EXIT_SUCCESS;
}