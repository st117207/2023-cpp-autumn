#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fi("INPUT.TXT");
	ofstream fo("OUTPUT.TXT");
	long long a, b;
	fi >> a>>b;
	fo <<a+b;
}
