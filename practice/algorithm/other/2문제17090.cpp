#include <iostream>
using namespace std;
int n, m;
char s[500][501];
int d[500][500];
int go(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 1;
    if (d[x][y] != -1)
        return d[x][y];
    d[x][y] = 0;
    if (s[x][y] == 'R')
    {
        d[x][y] = go(x, y + 1);
    }
    else if (s[x][y] == 'L')
    {
        d[x][y] = go(x, y - 1);
    }
    else if (s[x][y] == 'U')
    {
        d[x][y] = go(x - 1, y);
    }
    else
    {
        d[x][y] = go(x + 1, y);
    }
    return d[x][y];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            d[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] == -1)
            {
                go(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] == 1)
                ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
