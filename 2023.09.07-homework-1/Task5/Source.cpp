#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	ifstream fi("INPUT.TXT");
	ofstream fo("OUTPUT.TXT");
	int a, b, c, d;
	fi >> a >> b;
	c = a * b % 109;
	d = (c + 109) % 109 + 1;
	fo << d;
}