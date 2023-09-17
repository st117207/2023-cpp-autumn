#include <iostream>
int main(int argc, char* argv[])
{
  
    long long b=0, ch1=0, n=0, a=0, res=0, ch2=0, itog=0;
   std:: cin >> a;
    ch1 = a + 100000;
    ch2 = -a + 100000;
    res = (ch1 * (ch1 / ch2) + ch2 * (ch2 / ch1)) / (ch2 / ch1 + ch1 / ch2) - 100000;
    a = a - 1;
    b = -a;
    a = a + 100000;
    b = b + 100000;
    n = (a * (a / b) + b * (b / a)) / (b / a + a / b) - 100000;
    a = a - 100000 + 1;
    itog = (n *( (a*res) % (res+1) + 1 + a) / 2) + 1;
    std:: cout<< itog;
}