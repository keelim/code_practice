#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 1001

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<tuple<int, int, int>> q;

int main()
{

    cin >> m >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                visited[i][j] = true;
                q.push(make_tuple(i, j, 0));
            }
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 0 && !visited[nx][ny])
            {

                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, cnt+1));
            }
        }
        if(cnt>=count) count = cnt;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && !visited[i][j])
            {
                count = -1;
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}