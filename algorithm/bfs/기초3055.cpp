#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int wmap[50][50];
char map[50][50];
bool visited[50][50];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> start, endp;
queue<pair<int, int>> q;

int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            wmap[i][j] = 999;
            cin >> map[i][j];
            if (map[i][j] == 'S') // 시작
                start = {i, j};

            else if (map[i][j] == 'D') // 도착
                endp = {i, j};

            else if (map[i][j] == '*')
            {
                wmap[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[nx][ny] == '.' && wmap[nx][ny] > wmap[x][y] + 1) // 비어 있고 물맵 클떄
            {
                wmap[nx][ny] = wmap[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    } // 물맵 만들기

    
    queue < tuple<int, int, int>> nq;
    nq.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = 1;

    while (!nq.empty())
    {
        int x, y, cnt;
        tie(x, y, cnt) = nq.front();
        nq.pop();

        if (x == endp.first && y == endp.second) // 종료조건 도착지점 도착
        {
            cout << cnt << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (!visited[nx][ny] && map[nx][ny] != 'X' && wmap[nx][ny] > cnt + 1) // 물값보다 작다 그전에 들어온다
            {
                visited[nx][ny] = 1;
                nq.push(make_tuple(nx, ny, cnt + 1));
            }
        }
    }
    cout << "KAKTUS" << endl;
    return 0;
}
