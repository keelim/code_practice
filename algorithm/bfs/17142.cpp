#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
#define MAX 50
#define VIRUS_MAX 10

int map[MAX][MAX];
int visited[MAX][MAX];
int n, m;
int virusCount = 0;
int result = 987654321;
bool virusVisited[VIRUS_MAX];
vector<pair<int, int>> virus;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int a)
{
    queue<pair<int, int>> q;
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < a; i++)
    {
        if (virusVisited[i])
        {
            q.push(make_pair(virus[i].first, virus[i].second));
            visited[virus[i].first][virus[i].second] = 0;
        }
    }

    int check = 0;
    int time = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (map[nx][ny] != 1 && visited[nx][ny] == -1)
            {
                visited[nx][ny] = visited[x][y] + 1;
                if (map[nx][ny] == 0)
                {
                    check++;
                    time = visited[nx][ny];
                }
                q.push(make_pair(nx, ny));
            }
        }
    }
    if (check == virusCount)
        result = min(result, time);
}

void viusCheck(int index, int cnt, int size)
{
    if (cnt == m)
    {
        bfs(size);
        return;
    }
    for (int i = index; i < size; i++)
    {
        if (!virusVisited[i])
        {
            virusVisited[i] = true;
            viusCheck(i + 1, cnt + 1, size);
            virusVisited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back(make_pair(i, j));

            if (map[i][j] == 0)
                virusCount++;
        }
    }

    viusCheck(0, 0, virus.size());
    if (result == 987654321)
        cout << -1;

    else
        cout << result;
    
}