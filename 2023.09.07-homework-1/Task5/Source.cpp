#include <iostream>
int main(int argc, char* argv[])
{
	int a=0, b=0, c=0, d=0;
	std::cin >> a >> b;
	c = a * b % 109;
	d = (c + 109) % 109 + 1;
	std::cout<< d;
}