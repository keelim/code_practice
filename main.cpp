#include <string>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;

bool visited[105];
vector<pair<int, int>> map[105];

int solution (int n, vector<vector<int>> costs) {
	int answer=0;
	for (int i=0; i < costs.size (); i++) {
		int a=costs[i][0];
		int b=costs[i][1];
		int cost=costs[i][2];

		map[a].push_back ({ b, cost });
		map[b].push_back ({ a, cost });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (int i=0; i < map[0].size (); i++) {
		int x=map[0][i].first;
		int cost=map[0][i].second;
		pq.push ({ cost, x });
	}
	visited[0]=true;
	while (!pq.empty ()) {
		int cost, x;
		tie (cost, x)=pq.top ();
		pq.pop ();

		if (!visited[x]) {
			visited[x]=true;
			answer+=cost;

			for (int i=0; i < map[x].size (); i++) {
				int nx, ncost;
				tie (nx, ncost)=map[x][i];
				if (!visited[nx])
					pq.push ({ ncost, nx });
			}
		}
	}
	return answer;
}
