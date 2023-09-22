#include <iostream>

int main(int argc, char* argv[])
{
	long long m = 0;
	long long k = 0;
	long long n = 0;
	long long res = 0;
	long long j = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	j = n * 2;
	if (n <= k)
	{
		res = m*2;
	}
	else
	{
		res = j / k*m;
		if (j % k != 0)
		{
			res = res + m;
		}
	}
	std::cout << res;
	return EXIT_SUCCESS;

}