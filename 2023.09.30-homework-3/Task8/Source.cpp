#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	long long b = 0;
	long long c = 0;
	long long v1 = 0;
	long long v2 = 0;
	long long k = 0;
	long long h = 0;
	bool u = false;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if ((c > a) && (c > b))
	{
		std::cout << "Impossible";
	}
	while ((v1 != c) || (v2 != c))
	{
		v1 = a;
		if (v1 <= (b - v2))
		{
			v2 = v2 + v1;
			v1 = 0;
		}
		else
		{
			v1 = v1 - (b - v2);
			v2 = v1 % b;
			v1 = 0;
		}
		if ((v1 == c) || (v2 == c))
		{
			u = true;
			break;
		}
		k = k + 1;
		if (k > 100000)
		{
			break;
		}
	}
	v2 = 0;
	if (u == true)
	{
		while ((v1 != c) || (v2 != c))
		{
			v1 = a;
			std::cout << ">A" << std::endl;
			if (v1 <= (b - v2))
			{
				v2 = v2 + v1;
				std::cout << "A>B" << std::endl;
				v1 = 0;
			}
			else
			{
				h = v1 / b;
				v1 = v1 - (b - v2);
				v2 = v1 % b;
				std::cout << "A>B" << std::endl;
				if (((v1 != c) || (v2 != c)) && (h != 0))
				{
					std::cout << "B>" << std::endl;
				}
				for (int i = 0; i < h; i++)
				{
					std::cout << "A>B" << std::endl;

				}
				v1 = 0;
			}
			if ((v1 == c) || (v2 == c))
			{
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}