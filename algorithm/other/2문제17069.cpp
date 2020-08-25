#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;
int a[100][100];
long long d[100][100][3];
int n;
long long go(int x, int y, int dir)
{
    if (x == n - 1 && y == n - 1)
    {
        return 1;
    }
    long long &ans = d[x][y][dir];
    if (ans != -1)
        return ans;
    ans = 0;
    if (dir == 0)
    { // -
        if (y + 1 < n && a[x][y + 1] == 0)
        {
            ans += go(x, y + 1, 0);
        }
        if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0)
        {
            ans += go(x + 1, y + 1, 1);
        }
    }
    else if (dir == 1)
    { // dig
        if (y + 1 < n && a[x][y + 1] == 0)
        {
            ans += go(x, y + 1, 0);
        }
        if (x + 1 < n && a[x + 1][y] == 0)
        {
            ans += go(x + 1, y, 2);
        }
        if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0)
        {
            ans += go(x + 1, y + 1, 1);
        }
    }
    else if (dir == 2)
    { // |
        if (x + 1 < n && a[x + 1][y] == 0)
        {
            ans += go(x + 1, y, 2);
        }
        if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0)
        {
            ans += go(x + 1, y + 1, 1);
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(0, 1, 0) << '\n';
    return 0;
}
