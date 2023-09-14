#include <iostream>
int main(int argc, char* argv[])
{
	int a, b, c, d;
	std::cin >> a >> b;
	c = a * b % 109;
	d = (c + 109) % 109 + 1;
	std::cout<< d;
}