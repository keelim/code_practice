#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int gcd_a = a, gcd_b = b;
    while (gcd_b > 0)
    {
        int temp = gcd_b;
        gcd_b = gcd_a % gcd_b;
        gcd_a = temp;
    }

    int lcm = (a * b) / gcd_a;
    cout << gcd_a << "\n" << lcm;
}