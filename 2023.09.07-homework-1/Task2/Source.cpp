#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fi("INPUT.TXT");
    ofstream fo("OUTPUT.TXT");
    long long t, b, c, sum, ch, ch1, n, a, a1, res, ch2, itog, e;
    cin >> a;
    ch1 = a + 10001;
    ch2 = -a + 10001;
    res = (ch1 * (ch1 / ch2) + ch2 * (ch2 / ch1)) / (ch2 / ch1 + ch1 / ch2) - 10001;
    a = a - 1;
    b = -a;
    a = a + 10001;
    b = b + 10001;
    n = (a * (a / b) + b * (b / a)) / (b / a + a / b) - 10001;
    a = a - 10001 + 1;
    itog = (n *( (a*res) % (res+1) + 1 + a) / 2) + 1;
    cout << itog;
}