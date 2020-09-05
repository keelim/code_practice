#include <cstdio>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;
int d[101][101];
int a[101][101];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
            d[i][j] = -1;
        }
    } //input

    queue<pair<int, int>> q;
    queue<pair<int, int>> nq;
    q.push(make_pair(0, 0));
    d[0][0] = 0;
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m)
                continue;

            if (d[nx][ny] != -1)
                continue;

            if (a[nx][ny] == 0)
            {
                d[nx][ny] = d[x][y];
                q.push(make_pair(nx, ny));
            }
            else  // 벽을 만나면 
            {
                d[nx][ny] = d[x][y] + 1; // 어차피 도착하는 벽의 개수
                nq.push(make_pair(nx, ny));
            }
        }
        if (q.empty())
        {
            q = nq;
            nq = queue<pair<int, int>>(); // 벽을 다시 있을 때 다시 계산
        }
    }

    cout << d[n - 1][m - 1] << "\n";
    return 0;
}