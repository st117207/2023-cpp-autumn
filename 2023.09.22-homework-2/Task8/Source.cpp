#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int k = 0;
	std::cin >> a >> b >> c;
	switch (b <= c)
	{
	case true:
		break;
	case false:
		k = b;
		b = c;
		c = k;
		break;
	}
	switch (a <= b)
	{
	case true:
		break;
	case false:
		k = a;
		a = b;
		b = k;
		break;
	}
	switch (b <= c)
	{
	case true:
		break;
	case false:
		k = b;
		b = c;
		c = k;
		break;
	}
	std::cout << a << " " << b << " " << c;
	return EXIT_SUCCESS;
}