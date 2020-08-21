//example code bfs dfs --> 인접 리스트가 효과적일 수 있다.
#include <iostream>
#include <queue>

using namespace std;
bool visited[4];
int map[101][101];

void dfs(int x)
{
    visited[x] = 1;
    cout << x;
    for (int i = 0; i < n; i++)
    {
        if (map[x][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void dfs2(int x)
{
    visited[x] = 1;
    cout << x;
    for (int i = 0; i < map[x].size(); i++)
    {
        int y = a[x][i];
        if (!visited[y])
            dfs2(y);
    }
}

void bfs()
{
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!.qempty())
    {
        int x = q.front();
        q.pop();

        cout << x;
        for (int i = 0; i < n; i++)
        {
            if (map[x][i] && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

//플러드 필 어떤 위치와 전부 연결 된 모습

void bfs2()
{
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!.qempty())
    {
        int x = q.front();
        q.pop();

        cout << x;
        for (int i = 0; i < map[x].size(); i++)
        {
            int y = map[x][i];
            if (!visited[i])
            {
                visited[y] = 1;
                q.push(y);
            }
        }
    }
}

//2667 단지번호 붙이기 - 연결 요소 , 4963, 나이트 문제도 있다.
//이차원 배열에서는 굳이 할 필요 없다.

int main2667()
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] && !visited[i][j])
            {
                cnt++;
                bfs2667(i, j, cnt);
            }
        }
    }
}

void bfs(int x, int y, int cnt)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = cnt;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y = dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= m)
                continue;

            if (map[nx][ny] && d[x][y] == 0)
            {
                q.push(make_pair(nx, ny));
                d[nx][ny] = cnt;
            }
        }
    }
}

// 가장 중요한 BFS 임의 정정에서 모든 정점을 한번 씩 방문
// 최간거리를 구하는 알고리즘 // 모든 가중치 1일 때
// 단게별로 움직이기 때문이다.

//2178  BFS DFS 도착을 하는지를 하는 것이다. 7576
// 그래프로 변형을 하여
// 1697 숨박꼭질 위치를 이동하는 시간이 가중치가 될 수 있다.
// 가장 빠른 시간
// 방문 했는지, dist 를 2개

void bfs3()
{
    visited[n] = 1;
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now - 1 >= 0 && !visited[now - 1])
        {
            q.push(now - 1);
            visitedp[now - 1] = dist[now] + 1;
        }

        if (now + 1 < MAX && !visited[now + 1])
        {
            q.push(now + 1);
            visited[now + 1] = 1;
            dist[now + 1] = dist[now] + 1;
        }

        if (now * 2 < MAX && !visited[now + 1])
        {
            q.push(now * 2);
            visited[now * 2] = 1;
            dist[now * 2] = dist[now] + 1;
        }
    }
}

//파란 간선은 1개만 이용을 할 수 있다. 
//파란 가선을 기준으로 쪼개야 한다. 
// 정점을 쪼개야 한다. 

//14226
// 할 수 있는 선택이 달라서 정점을 쪼개야 한다. 
// 이모티콘 다시 듣기

// 덱을 사용을 하는 방법  Double ended queue
// bfs 할 때 사용하는 방법 가중치가 1일 때 
// 큐를 나누는 것이다. 
// 정점을 쪼개야 한다. 
// 3개의 상태를 





