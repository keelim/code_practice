#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > map;
vector<bool> visited;
int n, m;
int u, v;

void bfs(int a) { //인접 행렬 보다는 인접 그래프가 좋다.
    //하지만 행렬이면 다른 방식으로 쓸수는 있다.
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' '; //현재 원소

        for (int i = 0; i < map[x].size(); i++) {
            int nx = map[x][i];

            if (!visited[nx]) {
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    map.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        map[u].push_back(v);
    }
    bfs(1);
}
