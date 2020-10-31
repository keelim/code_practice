#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<bool> visited;
int n, m;
int u, v;

void dfs(int x) { //�⺻������ ��͸� ����Ѵٰ� �ϸ� �����ϱ� ����.
	visited[x] = true; //bfs ó�� �湮 �迭 ǥ�ø� �ϰ� 
	cout << x << ' ';
	for(auto ele : map[x]) { //������ �ִ� �ʿ��� Ȯ���� �Ѵ�. 
		if (visited[ele]) continue; //�湮�� ������ �湮 ���ϰ� 
		dfs (ele); //���
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
