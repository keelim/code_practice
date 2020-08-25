#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};

int cost[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int a[200][200];
int d[200][200][31] = {
    -1,
}; // k 번 이동은 전부 다르다.

int main()
{
    int l, n, m;
    cin >> l >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    d[0][0][0] = 0;
    q.push(make_tuple(0, 0, 0));
    while (!q.empty())
    {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        for (int k = 0; k < 12; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int ncnt = cnt + cost[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (a[nx][ny])
                continue; // 못가니까

            if (ncnt <= l && d[nx][ny][ncnt] == -1)
            {
                d[nx][ny][ncnt] = d[x][y][cnt] + 1;
                q.push(make_tuple(nx, ny, ncnt));
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= l; i++)
    {
        if (d[n - 1][m - 1][i] == -1)
            continue;
        if (ans == -1 || ans > d[n - 1][m - 1][i])
        {
            ans = d[n - 1][m - 1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}