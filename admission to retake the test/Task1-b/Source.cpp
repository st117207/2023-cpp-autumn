#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int sum = 0;
	std::cin >> n;
	while (n != 0)
	{
		sum = sum + (n & 1);
		n = n >> 1;
	}
	std::cout << sum;

	return EXIT_SUCCESS;
}