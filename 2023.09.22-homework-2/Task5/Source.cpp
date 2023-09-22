#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	if ((a % 10 == 1) && (a % 100 != 11))
	{
		std::cout << a << " bochka";
	}
	else if (((a % 10 == 2) && (a % 100 != 12)) || ((a % 10 == 3) && (a % 100 != 13)) || ((a % 10 == 4) && (a % 100 != 14)))
	{
		std::cout << a << " bochki";
	}
	else

	{
		std::cout << a << " bochek";
	}
	return EXIT_SUCCESS;
}