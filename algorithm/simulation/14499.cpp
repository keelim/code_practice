#include <iostream>
#include <vector>

using namespace std;

int n, m, sx, sy, k;
int map[20][20];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dice[7] = {0};

vector<int> vc;

void game(int d) //그냥 다 구현
{
    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1], d2 = dice[2], d3 = dice[3];
    d4 = dice[4], d5 = dice[5], d6 = dice[6];

    if (d == 0)
    {
        dice[1] = d4;
        dice[4] = d6;
        dice[6] = d3;
        dice[3] = d1;
    }
    else if (d == 1)
    {
        dice[4] = d1;
        dice[6] = d4;
        dice[3] = d6;
        dice[1] = d3;
    }
    else if (d == 2)
    {
        dice[1] = d5;
        dice[2] = d1;
        dice[6] = d2;
        dice[5] = d6;
    }
    else if (d == 3)
    {
        dice[5] = d1;
        dice[1] = d2;
        dice[2] = d6;
        dice[6] = d5;
    }
}

void solution()
{
    int x = sx;
    int y = sy;

    for (int i = 0; i < vc.size(); i++)
    {
        int nx = x + dx[vc[i]];
        int ny = y + dy[vc[i]];
        int d = vc[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        game(d);
        if (map[nx][ny] == 0)
            map[nx][ny] = dice[6];
            
        else
        {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[1] << "\n";

        x = nx;
        y = ny;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> sx >> sy >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        a = a - 1;
        vc.push_back(a);
    }

    solution();
}
