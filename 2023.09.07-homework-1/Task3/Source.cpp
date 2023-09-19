#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long b = 0;
	std::cin >> a;
	b = a / 10;
	b = b * b + b;
	std::cout << b * 100 + 25;
	return EXIT_SUCCESS;
}
