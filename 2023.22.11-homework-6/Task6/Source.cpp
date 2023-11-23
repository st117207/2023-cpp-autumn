#include <iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);

	return EXIT_SUCCESS;
}
void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int res = 6 - from - to;
		hanoi(n - 1, from, res);
		if (n != 1)
		{
			std::cout << 0 << " " << from << " " << to << std::endl;

		}
		else
		{
			std::cout << n << " " << 6 - from - to << " " << 3 << std::endl;
		}
		hanoi(n - 1, res, to);
	}
}