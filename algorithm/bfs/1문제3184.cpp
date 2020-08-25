#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n, m;
string map[250];
bool visited[250][250];
int d[250 * 250][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void bfs(int a, int b, int cnt)
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[x][y] == 'v')
        {
            d[cnt][0] ++;
        }
        else if (map[x][y] == 'o')
        {
            d[cnt][1] ++;
        }
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == '#')
                continue;
            if (visited[nx][ny])
                continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != '#' && !visited[i][j])
            {
                cnt ++;
                bfs(i, j, cnt);
            }
        }
    }
    int v = 0;
    int o = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (d[i][0] >= d[i][1])
        {
            v += d[i][0];
        }
        else
        {
            o += d[i][1];
        }
    }
    cout << o << ' ' << v << '\n';
    return 0;
}