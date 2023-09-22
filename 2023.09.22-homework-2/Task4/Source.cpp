#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int m60 = 0;
	int m20 = 0;
	int m10 = 0;
	int m5 = 0;
	int m1 = 0;
	int r = 0;
	std::cin >> a;
	m60 = a / 60;
	a = a % 60;
	if (a >= 36)
	{
		m60 = m60 + 1;
	}
	else
	{
		m20 = a / 20;
		a = a % 20;
		if (a >= 18)
		{
			m20 = m20 + 1;
		}
		else
		{
			m10 = a / 10;
			a = a % 10;
			if (a >= 9)
			{
				m10 = m10 + 1;
			}
			else
			{
				m5 = a / 5;
				m1 = m1 % 5;
			}
		}

		
	}
	std::cout << m1 << " " << m5 << " " << m10 << " " << m20 << " " << m60;
	return EXIT_SUCCESS;
}