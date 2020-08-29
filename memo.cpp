#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int cnt;
int map[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<tuple<int, int, int>> q;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                visited[i][j] = true;
                q.push(make_tuple(i, j, 0));
            }
        }

    while (!q.empty())
    {
        int x, y;
        tie(x, y, cnt) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push(make_tuple(nx, ny, cnt + 1));
            }
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 0 && !visited[i][j])
            {
                cnt = -1;
                break;
            }
        

    cout << cnt;
    return 0;
}