#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, V;
int map[1001][1001];
bool visited[1001];
queue<int> q; //대칭 일떄는 1개만

void dfs(int v)

{
    cout << v << " ";
    for (int i = 1; i <= n; i++)
        if (map[v][i] && !visited[i])
        {
            visited[i] = 1;
            //인접한 노드에 대해서 또 다시 dfs
            dfs(i);
        }
}

void bfs(int v)
{
    q.push(v);
    visited[v] = 1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        //bfs는 해당 노드에 인접한 노드들을 모두 추가한 뒤 bfs 진행
        for (int i = 1; i <= n; i++)
            if (map[v][i] && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
    }
}

int main()
{
    cin >> n >> m >> V;
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        map[first][second] = 1;
        map[second][first] = 1;
    }

    visited[V] = 1; //V에서 시작하므로

    dfs(V);

    cout << "\n";

    memset(visited, false, sizeof(visited));
    bfs(V);

    cout << "\n";

    return 0;
}