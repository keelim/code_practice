#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0}; //동 서 남 북
int dy[4] = {0, 0, -1, 1}; //동 서 남 북

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1)); //첫째pair 위치, 둘째pair 움직인거리
    visited[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int cnt = q.front().second;

        q.pop();

        if (x == m - 1 && y == n - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            if (!visited[ny][nx] && map[ny][nx] == '1')
            {
                q.push(make_pair(make_pair(ny, nx), cnt + 1));
                visited[ny][nx] = 1;
            }
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
    cout << bfs();

    return 0;
}