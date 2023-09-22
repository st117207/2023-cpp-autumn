// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p) {
    if (p == 0) return 1;
    int answer = x;
    for (int i = 1; i < p; i++)
    {
        answer = answer * x;
    }
    return answer;
}
#include <iostream>
using namespace std;
int main()
{ int a,b;
    cin >> a>>b;
    cout << power(a, b);
}