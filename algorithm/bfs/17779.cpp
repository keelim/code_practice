#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int five = 4;

int n, board[21][21], people[5], answer;
bool visited[21][21];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void selectFiveArea(int x, int y, int d1, int d2)
{
    int i, j;
    memset(people, 0, sizeof(people));
    memset(visited, 0, sizeof(visited));

    // 2. 5번 선거구 경계선
    for (i = 0; i <= d1; ++i)
    {
        visited[x + i][y - i] = true;
        visited[x + d2 + i][y + d2 - i] = true;
        people[five] += board[x + i][y - i] + board[x + d2 + i][y + d2 - i];
    }
    for (i = 1; i < d2; ++i)
    {
        visited[x + i][y + i] = true;
        visited[x + d1 + i][y - d1 + i] = true;
        people[five] += board[x + i][y + i] + board[x + d1 + i][y - d1 + i];
    }

    // 3. 5번 선거구 내부 탐색
    for (i = 0; i < d1; ++i)
    {
        j = 0;
        while (!visited[x + i + j + 1][y - i])
        {
            visited[x + i + j + 1][y - i] = true;
            people[five] += board[x + i + j + 1][y - i];
            j++;
        }
    }
    for (i = 1; i < d2; ++i)
    {
        j = 0;
        while (!visited[x + i + j + 1][y + i])
        {
            visited[x + i + j + 1][y + i] = true;
            people[five] += board[x + i + j + 1][y + i];
            j++;
        }
    }
    // 4. 1 ~ 4 선거구 선택
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (visited[i][j] == true)
                continue;
            if (i < x + d1 && j <= y)
                people[0] += board[i][j];
            else if (i <= x + d2 && y < j)
                people[1] += board[i][j];
            else if (x + d1 <= i && j < y - d1 + d2)
                people[2] += board[i][j];
            else if (x + d2 < i && y - d1 + d2 <= j)
                people[3] += board[i][j];
        }
    }

    // 5. 가장 작은 최대 인구, 최소 인구의 차이로 갱신
    pair<int *, int *> p = minmax_element(people, people + 5);
    answer = min(answer, int(*p.second - *p.first));
}

void divideArea()
{
    int x, y, d1, d2;

    // 1. 가능한 위치에서 d1, d2를 늘여가며 시도
    for (x = 1; x <= n - 2; ++x)
    {
        for (y = 2; y <= n - 1; ++y)
        {
            d1 = 1, d2 = 1;

            while (true)
            {
                if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n)
                    selectFiveArea(x, y, d1, d2++);
                else
                {
                    d1++, d2 = 1;
                    if (!(x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n))
                        break;
                }
            }
        }
    }
}

int main()
{
    cin >> n;

    int i, j;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            cin >> board[i][j];

    answer = 987654321;

    divideArea();

    cout << answer << "\n";
}