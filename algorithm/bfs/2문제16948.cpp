#include <iostream>
#include <tuple>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];
int main()
{
    int n;
    cin >> n;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    memset(dist, -1, sizeof(dist)); // 2차원은 이렇게 초기화를 해야 한다.
    //input 입력

    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= n)
                continue;

            if (dist[nx][ny] == -1)
            {
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    cout << dist[ex][ey] << '\n';
    //output
    return 0;
}