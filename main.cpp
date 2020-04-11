#include <iostream>

using namespace std;

int n, m, answer = 987654321;
char MAP[11][11];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> Red, Blue;

int Min(int A, int B)
{
    if (A < B)
        return A;
    return B;
}

int Move_Dist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}

int Inverse_Direction(int Cur_D)
{
    if (Cur_D == 0)
        return 1;
    else if (Cur_D == 1)
        return 0;
    else if (Cur_D == 2)
        return 3;
    else if (Cur_D == 3)
        return 2;
}

void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir)
{
    if (Cnt >= answer)
        return;
    if (Cnt > 10)
        return;

    bool Red_Flag = false;
    bool Blue_Flag = false;

    int nRx = Rx + dx[dir];
    int nRy = Ry + dy[dir];
    while (1)
    {
        if (MAP[nRx][nRy] == '#')
            break;
        if (MAP[nRx][nRy] == 'O')
        {
            Red_Flag = true;
            break;
        }
        nRx = nRx + dx[dir];
        nRy = nRy + dy[dir];
    }
    nRx = nRx - dx[dir];
    nRy = nRy - dy[dir];

    int nBx = Bx + dx[dir];
    int nBy = By + dy[dir];

    while (1)
    {
        if (MAP[nBx][nBy] == '#')
            break;

        if (MAP[nBx][nBy] == 'O')
        {
            Blue_Flag = true;
            break;
        }
        nBx = nBx + dx[dir];
        nBy = nBy + dy[dir];
    }
    nBx = nBx - dx[dir];
    nBy = nBy - dy[dir];

    if (Blue_Flag == true)
        return;
    else
    {
        if (Red_Flag == true)
        {
            answer = Min(answer, Cnt);
            return;
        }
    }

    if (nRx == nBx && nRy == nBy)
    {
        int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
        int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);

        if (Red_Dist > Blue_Dist)
        {
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else
        {
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (i == dir)
            continue;
        if (i == Inverse_Direction(dir))
            continue;

        Move(nRx, nRy, nBx, nBy, Cnt + 1, i);
    }
}

int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'R')
            {
                Red.first = i;
                Red.second = j;
                MAP[i][j] = '.';
            }
            else if (MAP[i][j] == 'B')
            {
                Blue.first = i;
                Blue.second = j;
                MAP[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int x = Red.first;
        int y = Red.second;
        int xx = Blue.first;
        int yy = Blue.second;

        Move(x, y, xx, yy, 1, i);
    }

    if (answer > 10 || answer == 987654321) answer= -1;
    if(answer>10) cout<<1<<"\n"    ;
    else cout<<0<<"\n";
    

    return 0;
}
