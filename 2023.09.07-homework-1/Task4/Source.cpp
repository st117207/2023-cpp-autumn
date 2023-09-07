#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fi("INPUT.TXT");
	ofstream fo("OUTPUT.TXT");
	int a,b;
	fi >> a;
	b = a * 100 + 90 + (9 - a);
	fo <<b;
}
