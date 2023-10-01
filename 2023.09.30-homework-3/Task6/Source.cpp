#include <iostream>

int main(int argc, char* argv[])
{
	long long n = 0;
	long long f1 = 1;
	long long f2 = 1;
	long long f3 = 1;
	std::cin >> n;

	for (int i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	std::cout << f3;
	return EXIT_SUCCESS;
}