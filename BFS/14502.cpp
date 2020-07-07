#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 8;
typedef struct
{
        int y, x;
} dir;

dir moveDir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
int lab[MAX][MAX];
int map[MAX][MAX];

int result;

void bfs()
{
        int afterSpread[MAX][MAX];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        afterSpread[i][j] = map[i][j];

        queue<pair<int, int>> q; //y, x

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        if (afterSpread[i][j] == 2)      //바이러스라면
                                q.push(make_pair(i, j)); //큐에 넣는다

        while (!q.empty())
        {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                        int nx = x + moveDir[i].x;
                        int ny = y + moveDir[i].y;
                        if (0 > nx || 0 > ny || nx >= m || ny >= n)
                                continue;

                        if (afterSpread[ny][nx] == 0) //빈칸이라면
                        {
                                afterSpread[ny][nx] = 2; //바이러스 감염
                                q.push(make_pair(ny, nx));
                        }
                }
        }

        int empty = 0;

        //빈칸 세기

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        if (afterSpread[i][j] == 0)
                                empty++;

        result = max(result, empty);
}

void makeWall(int cnt)
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
                                makeWall(cnt + 1);
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
                                makeWall(1);   //벽을 세운 상태이므로 cnt = 1
                                map[i][j] = 0; //다시 허문다
                        }

        cout << result << endl;

        return 0;
}