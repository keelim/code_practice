//구슬 탈출 2
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, answer = 987654321;
char map[11][11];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> red, blue;


int moveDist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}

int inverseDirection(int dir)
{
    if (dir == 0)
        return 1;
    else if (dir == 1)
        return 0;
    else if (dir == 2)
        return 3;
    else if (dir == 3)
        return 2;
}

void move(int rx, int ry, int bx, int by, int cnt, int dir)
{
    if (cnt >= answer)
        return;
    if (cnt > 10)
        return;

    bool redFlag = false;
    bool blueFlag = false;

    int nrx = rx + dx[dir];
    int nry = ry + dy[dir];
    while (1)
    {
        if (map[nrx][nry] == '#')
            break;
        if (map[nrx][nry] == 'O')
        {
            redFlag = true;
            break;
        }
        nrx = nrx + dx[dir];
        nry = nry + dy[dir];
    }
    nrx = nrx - dx[dir];
    nry = nry - dy[dir];

    int nbx = bx + dx[dir];
    int nby = by + dy[dir];

    while (1)
    {
        if (map[nbx][nby] == '#')
            break;

        if (map[nbx][nby] == 'O')
        {
            blueFlag = true;
            break;
        }
        nbx = nbx + dx[dir];
        nby = nby + dy[dir];
    }
    nbx = nbx - dx[dir];
    nby = nby - dy[dir];

    if (blueFlag == true)
        return;
    else
    {
        if (redFlag == true)
        {
            answer = min(answer, cnt);
            return;
        }
    }

    if (nrx == nbx && nry == nby)
    {
        int Red_Dist = moveDist(rx, ry, nrx, nry);
        int Blue_Dist = moveDist(bx, by, nbx, nby);

        if (Red_Dist > Blue_Dist)
        {
            nrx = nrx - dx[dir];
            nry = nry - dy[dir];
        }
        else
        {
            nbx = nbx - dx[dir];
            nby = nby - dy[dir];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (i == dir)
            continue;
        if (i == inverseDirection(dir))
            continue;

        move(nrx, nry, nbx, nby, cnt + 1, i);
    }
}

int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
            {
                red.first = i;
                red.second = j;
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B')
            {
                blue.first = i;
                blue.second = j;
                map[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int x = red.first;
        int y = red.second;
        int xx = blue.first;
        int yy = blue.second;

        move(x, y, xx, yy, 1, i);
    }

    if (answer > 10 || answer == 987654321) answer= -1;
        
    cout << answer << "\n";

}
