#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int n;
int a[500][500][2];
bool check[500][500];
pair<int, int> from[500][500];
int dist[500][500];
int dx0[6] = {-1, -1, 0, 0, 1, 1};
int dy0[6] = {-1, 0, -1, 1, -1, 0};
int dx1[6] = {-1, -1, 0, 0, 1, 1};
int dy1[6] = {0, 1, -1, 1, 0, 1};
bool ok(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (x % 2 == 0)
    {
        return y >= 0 && y < n;
    }
    else
    {
        return y >= 0 && y < n - 1;
    }
}
bool go(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        if (y1 < y2)
        {
            return a[x1][y1][1] == a[x2][y2][0];
        }
        else
        {
            return a[x1][y1][0] == a[x2][y2][1];
        }
    }
    else
    {
        if (x1 % 2 == 0)
        {
            if (y1 == y2)
            {
                return a[x1][y1][1] == a[x2][y2][0];
            }
            else
            {
                return a[x1][y1][0] == a[x2][y2][1];
            }
        }
        else
        {
            if (y1 == y2)
            {
                return a[x1][y1][0] == a[x2][y2][1];
            }
            else
            {
                return a[x1][y1][1] == a[x2][y2][0];
            }
        }
    }
}
int num(int x, int y)
{
    int ans = x / 2 * (n * 2 - 1);
    if (x % 2 == 1)
    {
        ans += n;
    }
    ans += y + 1;
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> a[i][j][0];
            cin >> a[i][j][1];
        }
        if (i % 2 == 0)
        {
            cin >> a[i][n - 1][0];
            cin >> a[i][n - 1][1];
        }
    }
    queue<pair<int, int>> q;
    check[0][0] = true;
    dist[0][0] = 1;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 6; k++)
        {
            int nx, ny;
            if (x % 2 == 0)
            {
                nx = x + dx0[k];
                ny = y + dy0[k];
            }
            else
            {
                nx = x + dx1[k];
                ny = y + dy1[k];
            }
            if (ok(nx, ny) == false)
                continue;
            if (go(x, y, nx, ny) == false)
                continue;
            if (check[nx][ny] == true)
                continue;
            check[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            from[nx][ny] = make_pair(x, y);
            q.push(make_pair(nx, ny));
        }
    }
    int x = n - 1;
    int y = n - 1;
    while (check[x][y] == false)
    {
        y -= 1;
        if (y < 0)
        {
            x -= 1;
            y = n - 1;
            if (x % 2 == 1)
            {
                y -= 1;
            }
        }
    }
    cout << dist[x][y] << '\n';
    stack<pair<int, int>> s;
    while (!(x == 0 && y == 0))
    {
        s.push(make_pair(x, y));
        auto p = from[x][y];
        x = p.first;
        y = p.second;
    }
    s.push(make_pair(x, y));
    while (!s.empty())
    {
        cout << num(s.top().first, s.top().second) << ' ';
        s.pop();
    }
    cout << '\n';
    return 0;
}