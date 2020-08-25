#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
int n, m;
int a[10][10];
int dist[10][10][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int bfs()
{
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 0;
    while (!q.empty())
    {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        if (a[x][y] >= 2 && t % a[x][y] != 0)
        {
            int nt = (t + 1) % a[x][y];
            if (dist[x][y][nt] == -1)
            {
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.push(make_tuple(x, y, nt));
            }
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n)
                {
                    if (a[x][y] >= 2 && a[nx][ny] >= 2)
                        continue;
                    if (a[nx][ny] >= 1)
                    {
                        int nt = (dist[x][y][t] + 1) % a[nx][ny];
                        if (dist[nx][ny][nt] == -1)
                        {
                            dist[nx][ny][nt] = dist[x][y][t] + 1;
                            q.push(make_tuple(nx, ny, nt));
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 20; i++)
    {
        if (dist[n - 1][n - 1][i] == -1)
            continue;
        if (ans == -1 || ans > dist[n - 1][n - 1][i])
        {
            ans = dist[n - 1][n - 1][i];
        }
    }
    return ans;
}
bool can(int i, int j)
{
    bool garo = false;
    if (j - 1 >= 0 && a[i][j - 1] == 0)
        garo = true;
    if (j + 1 < n && a[i][j + 1] == 0)
        garo = true;
    bool sero = false;
    if (i - 1 >= 0 && a[i - 1][j] == 0)
        sero = true;
    if (i + 1 < n && a[i + 1][j] == 0)
        sero = true;
    return !(garo && sero);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0 && can(i, j))
            {
                a[i][j] = m;
                int now = bfs();
                if (now != -1)
                {
                    if (ans == -1 || ans > now)
                    {
                        ans = now;
                    }
                }
                a[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}