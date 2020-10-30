#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

pair<int, int> moveDir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
int lab[8][8];
int map[8][8];
int spread[8][8];

int result;

void bfs()
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            spread[i][j] = map[i][j];

    queue<pair<int, int>> q; //y, x

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (spread[i][j] == 2)       //바이러스라면
                q.push(make_pair(i, j)); //큐에 넣는다

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + moveDir[i].first;
            int ny = y + moveDir[i].second;
            if (0 > nx || 0 > ny || nx >= n || ny >= m)
                continue;

            if (spread[nx][ny] == 0) //빈칸이라면
            {
                spread[nx][ny] = 2; //바이러스 감염
                q.push(make_pair(nx, ny));
            }
        }
    }

    int empty = 0;

    //빈칸 세기

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (spread[i][j] == 0)
                empty++;

    result = max(result, empty);
}

void wall(int cnt)
{
    if (cnt == 3) //벽을 세개 만들었으므로
    {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 0)
            {
                map[i][j] = 1; //마찬가지로 해당칸에 새우고
                wall(cnt + 1);
                map[i][j] = 0; //다시 허문다
            }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> lab[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (lab[i][j] == 0) //빈칸 발견 시
            {
                //연구실 상태를 복사한다
                for (int k = 0; k < n; k++)
                    for (int l = 0; l < m; l++)
                        map[k][l] = lab[k][l];

                map[i][j] = 1; //해당 칸에 벽을 세운다
                wall(1);       //벽을 세운 상태이므로 cnt = 1
                map[i][j] = 0; //다시 허문다
            }

    cout << result << endl;

    return 0;
}