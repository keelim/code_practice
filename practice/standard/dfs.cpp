#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<bool> visited;
int n, m;
int u, v;

void dfs(int x) { //기본적으로 재귀를 사용한다고 하면 생각하기 쉽다.
	visited[x] = true; //bfs 처럼 방문 배열 표시를 하고 
	cout << x << ' ';
	for(auto ele : map[x]) { //가지고 있는 맵에서 확인을 한다. 
		if (visited[ele]) continue; //방문을 했으면 방문 안하고 
		dfs (ele); //재귀
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
	dfs(1);
}
