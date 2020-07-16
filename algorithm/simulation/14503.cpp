#include <iostream>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];

pair<pair<int, int>, int> robot;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int turnDirection(int d)
{
    if (d == 0)
        return 3;
    else if (d == 1)
        return 0;
    else if (d == 2)
        return 1;
    else if (d == 3)
        return 2;
}

void solution()
{
    int x = robot.first.first;
    int y = robot.first.second;
    int d = robot.second;
    int room = 0;
    map[x][y] = 2;
    room++;

    int nx, ny, nd;

    while (1)
    {
        int temp = d;
        bool oclean = false;
        int noclean = 0;
        for (int i = 0; i < 4; i++) // 왼쪽방향으로부터 4방향 차례대로 탐색
        {
            nd = turnDirection(d);
            nx = x + dx[nd];
            ny = y + dy[nd];

            if (map[nx][ny] == 0)
            {
                oclean = true;
                break;
            }
            else if (map[nx][ny] == 1 || map[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= n || ny >= m))
            {
                d = nd;
                noclean++;
            }
        }

        if (oclean == true)
        {
            map[nx][ny] = 2;
            room++;
            d = nd;
        }

        if (noclean == 4)
        {
            nx = x - dx[temp];
            ny = y - dy[temp];
            d = temp;
            if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || map[nx][ny] == 1)
                break;
        }
        x = nx;
        y = ny;
    }
    cout << room << "\n";
}

int main(void)
{

    cin >> n >> m;
    cin >> robot.first.first >> robot.first.second >> robot.second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j]; //input

    solution();
}
