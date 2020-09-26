#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int s, e, c;
int start, arrive;
int dist[1001];
vector<pair<int, int>> map[1001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> c;
        map[s].push_back({c, e});            // 도시 간 연결 정보
    }
    cin >> start >> arrive;

    for (int i = 1; i <= n; i++) dist[i] = 987654321;                          // 초기값 설정은 불가능을 나타내는 이상치로 설정

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);                    // 우선순위 큐 선언해주고 시작점부터 계산시작
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;                         // 해당 도시까지의 최단거리값 저장해놓음
        int x = pq.top().second;                          // 이번에 검사할 도시와
        pq.pop();

        if (x == arrive) break;                                 // 도착점 도달 시 그냥 종료

        for (int i = 0; i < map[x].size(); i++)        // 해당 도시에 연결된 다른 도시들 검사
        {
            int ncost = map[x][i].first;
            int nx = map[x][i].second;
            if (dist[nx] > cost + ncost)           // 다른 도시들 중 최단거리 갱신할 수 있는 도시가 있다면
            {
                dist[nx] = cost + ncost;          // 업데이트 해주고
                pq.emplace(-dist[nx], nx);  // 큐에 넣어줌 (거리에 - 를 붙여 최단거리 확인)
            }
        }
    }

    cout << dist[arrive] << endl;
}