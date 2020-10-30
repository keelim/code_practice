#include <iostream>
#include <string>
using namespace std;
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
bool check(string &s, string &period)
{
    int g = period.length();
    for (int i = 0; i < s.length(); i += g)
    {
        if (s.substr(i, g) != period)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s, t;
    cin >> s >> t;
    int g = gcd(s.length(), t.length());
    string period = s.substr(0, g);
    if (check(s, period) && check(t, period))
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}
