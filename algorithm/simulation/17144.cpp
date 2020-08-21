#include <iostream>
#include <cstring>

#define MAX 50
using namespace std;

int r, c, t, answer;
int map[MAX][MAX];
int wmap[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<int, int> airCleaner[2];

void copyMap(int a[][MAX], int b[][MAX])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void dust()
{
    copyMap(wmap, map);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] != 0 && map[i][j] != -1)
            {
                int virusCount = 0;
                int value = map[i][j] / 5;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                        continue;

                    if (map[nx][ny] != -1)
                    {
                        wmap[nx][ny] = wmap[nx][ny] + value;
                        virusCount++;
                    }
                }
                wmap[i][j] -= (virusCount * value);
            }
        }
    }
    copyMap(map, wmap);
}

void moveDust()
{
    for (int index = 0; index < 2; index++)
    {
        if (index == 0)
        {
            // 1. 공기청정기 위에서부터 (0, 0)까지 모든 값 떙겨주기
            for (int i = airCleaner[index].first - 1; i > 0; i--)
            {
                map[i][0] = map[i - 1][0];
            }
            // 2. 가장 윗줄 땡겨주기
            for (int i = 0; i < c - 1; i++)
            {
                map[0][i] = map[0][i + 1];
            }
            // 3. 반대편 세로라인 땡겨주기
            for (int i = 1; i <= airCleaner[index].first; i++)
            {
                map[i - 1][c - 1] = map[i][c - 1];
            }
            // 4. 공기청정기 라인 땡겨주기
            for (int i = c - 1; i > 1; i--)
            {
                map[airCleaner[index].first][i] = map[airCleaner[index].first][i - 1];
            }
            map[airCleaner[index].first][1] = 0;
        }
        else
        {
            for (int i = airCleaner[index].first + 1; i < r - 1; i++)
            {
                map[i][0] = map[i + 1][0];
            }
            for (int i = 0; i < c - 1; i++)
            {
                map[r - 1][i] = map[r - 1][i + 1];
            }
            for (int i = r - 1; i >= airCleaner[index].first; i--)
            {
                map[i][c - 1] = map[i - 1][c - 1];
            }
            for (int i = c - 1; i > 1; i--)
            {
                map[airCleaner[index].first][i] = map[airCleaner[index].first][i - 1];
            }
            map[airCleaner[index].first][1] = 0;
        }
    }
}

int countDust()
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == -1)
                continue;
            sum += map[i][j];
        }
    }
    return sum;
}

int main()
{
    cin >> r >> c >> t;
    int index = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
            {
                airCleaner[index].first = i;
                airCleaner[index].second = j;
                index++;
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        dust();
        moveDust();
    }

    answer = countDust();

    cout << answer << "\n";
}
