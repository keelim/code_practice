#include <iostream>
#include <queue>

#define endl "\n"
#define MAX 50
using namespace std;

int n, m;
int wmap[MAX][MAX];
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> startp, endp;
queue<pair<int, int>> q;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            wmap[i][j] = 999;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                startp = {i, j};
            }
            else if (map[i][j] == 'D')
            {
                endp = {i, j};
            }
            else if (map[i][j] == '*')
            {
                wmap[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
}

void Make_WaterMap()
{
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[nx][ny] == '.' && wmap[nx][ny] > wmap[x][y] + 1)
            {
                wmap[nx][ny] = wmap[x][y] + 1;
                q.push(make_pair(nx, ny));
            } // 몇번을 갔는지를 보여주는 함수 구나
        }
    }
}

// 그니까 bfs를 두번 하는 것 하나는 얼마나 걸렸는지 표시
// 하나는 움직이는 것


void Move()
{
    queue<pair<pair<int, int>, int>> mq;
    mq.push(make_pair(make_pair(startp.first, startp.second), 0));
    visited[startp.first][startp.second] = true;

    while (!mq.empty())
    {
        int x = mq.front().first.first;
        int y = mq.front().first.second;
        int cnt = mq.front().second;
        mq.pop();

        if (x == endp.first && y == endp.second)
        {
            cout << cnt << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (visited[nx][ny] == false && map[nx][ny] != 'X' && wmap[nx][ny] > cnt + 1)
            {
                visited[nx][ny] = true;
                mq.push(make_pair(make_pair(nx, ny), cnt + 1));
            }
        }
    }
    cout << "KAKTUS" << endl;
}

int main(void)
{
    input();
    Make_WaterMap();
    Move();
}
