#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > map;
vector<bool> visited;
int n, m;
int u, v;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << ' ';
    for (int i = 0; i < map[cur].size(); i++) {
        int next = map[cur][i];
        if (visited[next]) continue;
        dfs(next);
    }
}

int main() {
    cin >> n >> m;
    map.resize(n + 1);
    visited.resize(n + 1); //visited = vector<bool> ();

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        map[u].push_back(v);
    }
    dfs(1);
}
