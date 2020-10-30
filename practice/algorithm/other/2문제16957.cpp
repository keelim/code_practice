#include <iostream>
using namespace std;
int a[500][500];
int ans[500 * 500];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int parent[500 * 500];
int go(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return go(parent[x]);
    }
}
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = i;
            int y = j;
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m)
                {
                    if (a[nx][ny] < a[x][y])
                    {
                        x = nx;
                        y = ny;
                    }
                }
            }
            parent[i * m + j] = x * m + y;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[go(i * m + j)] += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i * m + j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
