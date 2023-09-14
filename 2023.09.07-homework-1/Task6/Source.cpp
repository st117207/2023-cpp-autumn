#include <iostream>
int main(int argc, char* argv[])
{
	long a,b,c,d;
	std::cin >> a>>b;
	std::cout << (a * (a/b) + b*(b/a))/(b/a+a/b);


}
