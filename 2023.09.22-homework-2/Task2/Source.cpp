#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	if (((b == 1) && (a == 1)) || ((b != 1) && (a != 1)))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;;
	}
	return EXIT_SUCCESS;
}