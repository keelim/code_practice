#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[1001][1001];
int d[1001][1001][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    d[0][0][0] = 1; //시작이니까?

    q.push(make_tuple(0, 0, 0)); //0을 먼저 넣어 준다.

    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (a[nx][ny] == 0 && d[nx][ny][z] == 0)
            {
                d[nx][ny][z] = d[x][y][z] + 1; // 하나를 늘려 준다,
                q.push(make_tuple(nx, ny, z));
            }

            if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z] == 0)
            {
                d[nx][ny][z + 1] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }
        }
        if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0)
        {
            cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
        }
        else if (d[n - 1][m - 1][0] != 0)
        {
            cout << d[n - 1][m - 1][0];
        }
        else if (d[n - 1][m - 1][1] != 0)
        {
            cout << d[n - 1][m - 1][1];
        }
        else
        {
            cout << -1;
        }
        cout << endl;

        return 0;
    }
}


// 숨박꼭질 3 
// 알고스팟