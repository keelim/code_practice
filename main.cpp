#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 1000 + 1;
int N, M, V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;
void dfs(int idx)

{
    cout << idx << " ";
    for (int i = 1; i <= N; i++)
        if (map[idx][i] && !visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }
}

void bfs(int idx)
{
    q.push(idx);
    visited[idx] = 1;
    while (!q.empty())
    {
        idx = q.front();
        q.pop();
        cout << idx << " ";

        //bfs는 해당 노드에 인접한 노드들을 모두 추가한 뒤 bfs 진행

        for (int i = 1; i <= N; i++)
            if (map[idx][i] && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
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

}