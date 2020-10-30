#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = x * a + y * b;
    for (int i = 1; i <= 100000; i++)
    {
        int price = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
        if (ans > price)
            ans = price;
    }
    cout << ans << '\n';
    return 0;
}
