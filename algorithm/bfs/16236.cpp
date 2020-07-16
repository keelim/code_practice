#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 20
using namespace std;

typedef struct
{
    int x;
    int y;
    int size;
    int eatNum;
    int time;
} Shark;

typedef struct
{
    int x;
    int y;
    int dist;
} Food;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];

Shark shark;
vector<Food> vc;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visited[a][b] = true;

    while (q.empty() == 0)
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int distance = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n > ny >= n)
                continue;

            if (!visited[nx][ny])
            {
                if (map[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), distance + 1));
                }
                else if (map[nx][ny] < shark.size)
                {
                    Food temp;
                    temp.x = nx;
                    temp.y = ny;
                    temp.dist = distance + 1;

                    vc.push_back(temp);
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), distance + 1));
                }
                else if (map[nx][ny] == shark.size)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), distance + 1));
                }
            }
        }
    }
}

bool sortStandard(Food a, Food b)
{
    if (a.dist <= b.dist)
    {
        if (a.dist == b.dist)
        {
            if (a.x <= b.x)
            {
                if (a.x == b.x)
                {
                    if (a.y < b.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                shark.x = i;
                shark.y = j;
                shark.size = 2;
                shark.eatNum = 0;
                shark.time = 0;
            }
        }
    }

    while (1)
    {
        vc.clear();
        memset(visited, false, sizeof(visited));

        bfs(shark.x, shark.y);
        if (vc.size() == 0)
        {
            cout << shark.time << "\n";
            break;
        }
        else if (vc.size() == 1)
        {
            map[vc[0].x][vc[0].y] = 9;
            map[shark.x][shark.y] = 0;
            shark.x = vc[0].x;
            shark.y = vc[0].y;
            shark.eatNum++;
            shark.time += vc[0].dist;

            if (shark.eatNum == shark.size)
            {
                shark.eatNum = 0;
                shark.size++;
            }
        }
        else
        {
            sort(vc.begin(), vc.end(), sortStandard);
            map[vc[0].x][vc[0].y] = 9;
            map[shark.x][shark.y] = 0;
            shark.x = vc[0].x;
            shark.y = vc[0].y;
            shark.eatNum++;
            shark.time += vc[0].dist;

            if (shark.eatNum == shark.size)
            {
                shark.eatNum = 0;
                shark.size++;
            }
        }
    }
}
