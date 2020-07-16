#include <iostream>
#include <queue>
using namespace std;

struct pipe
{
    int x, y, dir;
};

queue<pipe> q;
int map[17][17] = {
    0,
};

int n= 0;
int dx[3] = {0, 1, 1}; // row, col, cross
int dy[3] = {1, 0, 1}; // row, col, cross

int bfs(int x, int y, int dir)
{
    int count = 0;
    q.push({x, y, dir});
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop(); 

        if (x == n - 1 && y == n - 1) //끝까지 오면
            count++;

        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndir = i;
            if ((ndir + dir) != 1)
            { // (row to col) or (col to row)
                if (nx >= n || ny >= n || map[nx][ny]) continue;

                    if (i == 2)
                    { // cross
                        if (!map[nx - 1][ny] && !map[nx][ny - 1])
                        {
                            q.push({nx, ny, ndir});
                        }
                    }
                    else
                    {
                        q.push({nx, ny, ndir});
                    }
            }
        }
    }
    return count;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    cout << bfs(0, 1, 0); //출력
}