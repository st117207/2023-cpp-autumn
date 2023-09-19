#include <iostream>

int main(int argc, char* argv[])
{
	long a = 0;
	long b = 0;
	std::cin >> a;
	std::cin >> b;
	std::cout << (a * (a / b) + b * (b / a)) / (b / a + a / b);
	return EXIT_SUCCESS;

}
