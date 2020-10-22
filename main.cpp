#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10001];
vector<pair<int, int>> map[10001];

/* ���� �˰���
   �켱���� ť�� �̿��Ͽ� �湮�� �� �ִ� ������ ����ġ�� ���� ���� �������� �̵�
   ������ ElogV �� �ð����⵵
*/

int prim () {
	long long ans=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// first�� ����ġ second �� ���� minheap 
	pq.push ({ 0,1 });

	while (!pq.empty ()) {
		pair<int, int> x=pq.top ();
		pq.pop ();

		if (visited[x.second]) continue;
		visited[x.second]=1;

		ans+=x.first;
		for (int i=0; i < map[x.second].size (); i++) {
			//���� �������� �̵� �� �� �ִ� �湮���� ���� ���� Ǫ�� 
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
