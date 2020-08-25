#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
#include <cstring>
using namespace std;
int a[1000][1000];
int d[1000][1000][11];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    int n, m, l;
    cin>>n>>m>>l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]); //하나씩 입력을 하는 방법
        }
    }
    queue<tuple<int, int, int>> q;
    d[0][0][0] = 1;
    q.push(make_tuple(0, 0, 0));
    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (a[nx][ny] == 0 && d[nx][ny][z] == 0)
            {
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
            if (z + 1 <= l && a[nx][ny] == 1 && d[nx][ny][z + 1] == 0)
            {
                d[nx][ny][z + 1] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= l; i++)
    {
        if (d[n - 1][m - 1][i] == 0)
            continue;
        if (ans == -1)
        {
            ans = d[n - 1][m - 1][i];
        }
        else if (ans > d[n - 1][m - 1][i])
        {
            ans = d[n - 1][m - 1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}