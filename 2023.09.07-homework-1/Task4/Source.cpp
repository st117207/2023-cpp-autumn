#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	b = a * 100 + 90 + (9 - a);
	std::cout << b;
	return EXIT_SUCCESS;
}
