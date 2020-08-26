#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b, c;
    cin >> b >> c;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1;
        a[i] -= b;
        if (a[i] < 0)
            a[i] = 0;
        ans += a[i] / c;
        if (a[i] % c != 0)
        {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}