#include<iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
	return 0;
}

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		if (n == 1)
		{
			std::cout << n << " " << from << " " << to << std::endl;

		}
		else
		{
			int res = 6 - from - to;
			hanoi(n - 1, from, to);
			std::cout << n << " " << from << " " << res << std::endl;
			hanoi(n - 1, to, from);
			std::cout << n << " " << res << " " << to << std::endl;
			hanoi(n - 1, from, to);

		}
	}

}