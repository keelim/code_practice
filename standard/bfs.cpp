#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<bool> visited;
int n, m;
int u, v;

void bfs(int a) {
	//bfs 는 기본적으로 queue 를 사용한다.
	queue<int> q;
	visited[a] = 1;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < map[x].size(); i++) {
			int nx = map[x][i];
			if (visited[nx]) continue;
			visited[nx] = true;
			q.push(nx);
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
