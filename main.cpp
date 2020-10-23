#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10001];
vector<pair<int, int>> map[10001];

/* 프링 알고리즘
   우선순위 큐를 이용하여 방문할 수 있는 정점중 가중치가 가장 낮은 정점으로 이동
   프림은 ElogV 의 시간복잡도
*/

int prim () {
	long long ans=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// first는 가중치 second 는 정점 minheap 
	pq.push ({ 0,1 });

	while (!pq.empty ()) {
		pair<int, int> x=pq.top ();
		pq.pop ();

		if (visited[x.second]) continue;
		visited[x.second]=1;

		ans+=x.first;
		for (int i=0; i < map[x.second].size (); i++) {
			//현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬 
			if (!visited[map[x.second][i].second]) {
				pq.push (map[x.second][i]);
			}
		}
	}
	return ans;
}

int main () {
	int n, m;
	cin >> n >> m;

	for (int i=0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back ({ c, b });
		map[b].push_back ({ c, a });
	}

	long long result=prim ();
	cout << result << '\n';
	return 0;
}
