#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;

int map[1001][1001];

int visited[1001][1001][2]; //마지막 2는 벽 뚫기 여부

int BFS(void)

{

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1)); //시작점, 벽 뚫기 가능
    visited[0][0][1] = 1;
    while (!q.empty())
    {
        int x, y, block;
        tie(x, y, block) = q.front();
        q.pop();

        //도착하면

        if (x == n - 1 && y == m - 1)
            return visited[x][y][block]; //시작하는 칸도 포함

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            //벽이 있고, 벽을 아직 안 뚫었다면
            if (map[nx][ny] == 1 && block)
            {
                visited[nx][ny][block - 1] = visited[x][y][block] + 1;
                q.push(make_tuple(nx, ny, block - 1));
            }

            //벽이 없고 방문하지 않았던 곳이라면
            else if (map[nx][ny] == 0 && visited[nx][ny][block] == 0)
            {
                visited[nx][ny][block] = visited[x][y][block] + 1;
                q.push(make_tuple(nx, ny, block));
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    cout << BFS() << "\n";
}