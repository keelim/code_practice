#include <iostream>
#include <algorithm>
using namespace std;

int n, m, answer;
int map[501][501];
bool visited[501][501] = {
    false,
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int exCase[4][4][2] = {
    {{0, 0}, {0, -1}, {0, 1}, {-1, 0}},
    {{0, 0}, {-1, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, -1}, {0, 1}, {1, 0}},
    {{0, 0}, {-1, 0}, {1, 0}, {0, -1}}};

void dfs(int x, int y, int cnt, int sum)
{
    // 테트로미노를 만든 경우
    if (cnt == 4)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

// 'ㅗ' 의 경우 예외처리
// 4방향 x 정사각형 4개
void getExceptionCase(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        bool flag = true;
        int sum = 0;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + exCase[i][j][0];
            int ny = y + exCase[i][j][1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                flag = false;
                break;
            }

            sum += map[nx][ny];
        }

        if (flag)
            answer = max(answer, sum);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    } //입력
    answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = false;

            // 'ㅗ' 의 경우 예외처리
            getExceptionCase(i, j); //새로운 dfs
        }
    }

    cout << answer << "\n";