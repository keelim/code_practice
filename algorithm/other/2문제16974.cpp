#include <iostream>
using namespace std;
long long d[51];
long long p[51];
long long go(int n, long long x)
{
    if (n == 0)
    {
        if (x == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if (x == 1)
    {
        return 0;
    }
    else if (x <= 1 + d[n - 1])
    {
        return go(n - 1, x - 1);
    }
    else if (x == 1 + d[n - 1] + 1)
    {
        return p[n - 1] + 1;
    }
    else if (x <= 1 + d[n - 1] + 1 + d[n - 1])
    {
        return p[n - 1] + 1 + go(n - 1, x - 1 - d[n - 1] - 1);
    }
    else
    {
        return p[n - 1] + 1 + p[n - 1];
    }
}
int main()
{
    int n;
    long long x;
    cin >> n >> x;
    d[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1 + d[i - 1] + 1 + d[i - 1] + 1;
        p[i] = p[i - 1] + 1 + p[i - 1];
    }
    cout << go(n, x) << '\n';
    return 0;
}
