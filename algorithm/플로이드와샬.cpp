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


// 플로이드 와샬 2
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321
#define ARR_SIZE 100 + 1
int node, edge;
int map[ARR_SIZE][ARR_SIZE];
int start, arrive, weight;

void floyd_warshall() {
    for (int i = 1; i <= node; i++)             // i vertex를 거치는 경우
        for (int j = 1; j <= node; j++)         // start node
            for (int k = 1; k <= node; k++)     // arrive node
                if (map[j][i] != INF && map[i][k] != INF)
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
}

int main() {
    cin >> node >> edge;
    for (int i = 1; i <= node; i++) {        // vectex table 초기화
        for (int j = 1; j <= node; j++) {
            map[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) {    // start vertex에서 arrive node 입력, 가중치 입력
        cin >> start >> arrive >> weight;
        if (map[start][arrive] > weight)
            map[start][arrive] = weight;
    }

    floyd_warshall();

    for (int i = 1; i <= node; i++) {
        for (int j = 1; j <= node; j++) {
            if (i == j || map[i][j] == INF)
                cout << 0 << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

