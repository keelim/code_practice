#include <algorithm>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

void bfs(int a, int b, int target)
{ //x //y
    q.push(make_pair(a, b));
    int value = 0;
    visited[b][a] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        value++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (!visited[ny][nx] && map[ny][nx] == target)
            {
                q.push(make_pair(nx, ny));
                visited[ny][nx] = 1;
            }
        }
    }
}

void bfs2(int a, int b)
{ //x //y
    q.push(make_pair(a, b));
    int value = 0;
    visited[b][a] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        value++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (!visited[ny][nx] && (map[ny][nx] == 2 || map[ny][nx] == 0))
            {
                q.push(make_pair(nx, ny));
                visited[ny][nx] = 1;
            }
        }
    }
}


//R 0 B 1 G 2
int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char chars[n];
        cin >> chars;

        for (int j = 0; j < n; j++)
        {
            char a = chars[j];
            if (a == 'R')
                map[i][j] = 0;
            else if (a == 'B')
                map[i][j] = 1;
            else
                map[i][j] = 2;
        }
    } //input

    //적록색이 같은걸로 보인다.
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    { // y
        for (int j = 0; j < n; j++)
        { // j
            if (map[i][j] == 0 && !visited[i][j])
            {
                c1++;
                bfs(j, i, 0);
            }
        }
    }

    for (int i = 0; i < n; i++)
    { // y
        for (int j = 0; j < n; j++)
        { // j
            if (map[i][j] == 1 && !visited[i][j])
            {
                c1++;
                bfs(j, i, 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    { // y
        for (int j = 0; j < n; j++)
        { // j
            if (map[i][j] == 2 && !visited[i][j])
            {
                c1++;
                bfs(j, i, 2);
            }
        }
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    { // y
        for (int j = 0; j < n; j++)
        { // j
            if ((map[i][j] == 2 || map[i][j] == 0) && !visited[i][j])
            {
                c2++;
                bfs2(j, i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    { // y
        for (int j = 0; j < n; j++)
        { // j
            if (map[i][j] == 1 && !visited[i][j])
            {
                c2++;
                bfs(j, i, 1);
            }
        }
    }

    cout << c1 << " "<< c2;
}