#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int map[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    ;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if (x == m - 1 && y == n - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (visit[nx][ny] == 1)
                continue;
            if (map[nx][ny] != 1)
                continue;

            q.push(make_pair(make_pair(nx, ny), cnt + 1));
            visit[nx][ny] = 1;
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = temp[j];
        }
    }

    cout << bfs();

    return 0;
}