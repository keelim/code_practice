#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 50
using namespace std;

int n, l, r;
int map[MAX][MAX];
int visited[MAX][MAX];
int countryNum;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool check = true;

bool canComb2(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        {
            if (l <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= r)
                return true;
        }
    }
    return false;
}

bool canComb(int x, int y, int xx, int yy)
{
    if (l <= abs(map[x][y] - map[xx][yy]) && abs(map[x][y] - map[xx][yy]) <= r)
        return true;
    return false;
}

void bfs(int a, int b)
{
    queue<pair<int, int>> q, nq;
    q.push(make_pair(a, b));
    nq.push(make_pair(a, b));
    visited[a][b] = true;
    int sum = 0;
    int virusCount = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        sum = sum + map[x][y];
        virusCount = virusCount + 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visited[nx][ny] != 0)
                continue;
            if (canComb(x, y, nx, ny) == true)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                nq.push(make_pair(nx, ny));
            }
        }
    }

    int value = sum / virusCount;

    while (nq.empty() == 0)
    {
        int x = nq.front().first;
        int y = nq.front().second;
        nq.pop();
        map[x][y] = value;
    }
}

void print()
{
    cout << "########################################"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << visited[i][j] << " ";
            }
        }

        cout << "\t\t";
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "########################################"
         << "\n";
}

int main(void)
{

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    //input

    int Day = 0;
    while (check)
    {
        //Print();
        check = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0 && canComb2(i, j) == true)
                {
                    bfs(i, j);
                    check = true;
                }
            }
        }
        if (check == true)
            Day++;
        memset(visited, false, sizeof(visited));
    }

    cout << Day << "\n";
}
