#include <iostream>
#include <cmath>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	int sum = 0;
	for (int i = 0; i < abs(a); i++)
	{
		for (int j = 0; j < abs(b); j++)
		{
			sum = sum + 1;
		}
	}
	int sign_a = -1;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < abs(b); j++)
		{
			sign_a = sign_a + 2;
			break;
		}
		break;
	}
	int sign_b = -1;
	for (int i = 0; i < abs(a); i++)
	{
		for (int j = 0; j < b; j++)
		{
			sign_b = sign_b + 2;
			break;
		}
		break;
	}
	std::cout << sign_a * sign_b * sum;

	return EXIT_SUCCESS;
}