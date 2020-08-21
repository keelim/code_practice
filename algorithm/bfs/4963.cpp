/* 1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 */
// 종료 조건

// 0
// 1
// 1
// 3
// 1
// 9

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;

int map[51][51];
bool visited[51][51];

void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (!visited[nx][ny] && map[nx][ny])
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    while (1)
    {
        cin >> m >> n;
        if (n + m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
            }
        } //input

        

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && map[i][j])
                {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        cout << cnt << endl;
        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
    }
}
