// 플로이드-워셜 알고리즘
#include <iostream>

using namespace std;

#define MAX  987654321
int n, m, map[501][501];

int main() {

    cin >> n >> m;    // n: 노드개수, m: 간선개수
    for (int i = 0; i < 501; ++i) {
        fill(map[i], map[i] + 501, MAX);
        map[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        // 굳이 갱신할 필요가 없는 경우, 갱신하지 않는다.
        if (map[a][b] != MAX && map[a][b] < c)
            continue;

        map[a][b] = c;
    }
    // 플로이드-워셜 알고리즘 O(n^3)
    for (int i = 1; i <= n; ++i)         // k번째 노드에 대해 테이블 갱신
        for (int j = 1; j <= n; ++j)     // 모든 출발 정점에 대해 반복
            for (int k = 1; k <= n; ++k) // 모든 도착 정점에 대해 반복
                map[j][k] = min(map[j][k], map[j][i] + map[i][k]);

    // 수행 결과를 출력
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == MAX)
                cout << "INF" << ' ';
            else
                cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}