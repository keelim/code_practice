#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100 + 1
using namespace std;

struct SharkInfo
{
    int r;
    int c;
    int speed;
    int direct;
    int size;
    int num;
};

int r, c, m, answer;
vector<int> map[MAX][MAX];
vector<SharkInfo> shark;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

bool Standard(int a, int b)
{
    if (shark[a].size > shark[b].size)
        return true;
    return false;
}

bool check()
{
    for (int i = 0; i < shark.size(); i++)
    {
        if (shark[i].size != 0)
            return false;
    }
    return true;
}

void fishing(int index)
{
    for (int i = 1; i <= r; i++)
    {
        if (map[i][index].size() != 0)
        {
            answer += shark[map[i][index][0]].size;
            shark[map[i][index][0]].size = 0;
            map[i][index].clear();
            break;
        }
    }
}

void moveShark()
{
    for (int i = 0; i < shark.size(); i++)
    {
        if (shark[i].size == 0)
            continue;
        int x = shark[i].r;
        int y = shark[i].c;
        map[x][y].clear();
    }

    for (int i = 0; i < shark.size(); i++)
    {
        if (shark[i].size == 0)
            continue;
        int x = shark[i].r;
        int y = shark[i].c;
        int direct = shark[i].direct;
        int speed = shark[i].speed;

        if (direct == 1 || direct == 2)
        {
            int rotate = (r - 1) * 2;
            if (speed >= rotate)
                speed = speed % rotate;

            for (int j = 0; j < speed; j++)
            {
                int nx = x + dx[direct];
                int ny = y + dy[direct];
                if (nx < 1)
                {
                    direct = 2;
                    nx = nx + 2;
                }
                if (nx > r)
                {
                    direct = 1;
                    nx = nx - 2;
                }
                x = nx;
                y = ny;
            }
        }
        else
        {
            int rotate = (c - 1) * 2;
            if (speed >= rotate)
                speed = speed % rotate;

            for (int j = 0; j < speed; j++)
            {
                int nx = x + dx[direct];
                int ny = y + dy[direct];
                if (ny < 1)
                {
                    direct = 3;
                    ny = ny + 2;
                }
                if (ny > c)
                {
                    direct = 4;
                    ny = ny - 2;
                }
                x = nx;
                y = ny;
            }
        }

        shark[i].r = x;
        shark[i].c = y;
        shark[i].direct = direct;
        map[x][y].push_back(i);
    }
}

void killShark()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (map[i][j].size() > 1)
            {
                sort(map[i][j].begin(), map[i][j].end(), Standard);
                int Live_Index = map[i][j][0];
                for (int k = 1; k < map[i][j].size(); k++)
                {
                    shark[map[i][j][k]].size = 0;
                    shark[map[i][j][k]].r = -1;
                    shark[map[i][j][k]].c = -1;
                }
                map[i][j].clear();
                map[i][j].push_back(shark[Live_Index].num);
            }
        }
    }
}

int main(void)
{

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.push_back({r, c, s, d, z, i});
        map[r][c].push_back(i);
    }

    if (m == 0)
    {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i <= c; i++)
    {
        if (check() == true)
            break;
        fishing(i);
        moveShark();
        killShark();
    }
    cout << answer << "\n";
}
