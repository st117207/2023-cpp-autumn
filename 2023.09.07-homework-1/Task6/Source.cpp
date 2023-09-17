#include <iostream>
int main(int argc, char* argv[])
{
	long a=0,b=0;
	std::cin >> a>>b;
	std::cout << (a * (a/b) + b*(b/a))/(b/a+a/b);


}
