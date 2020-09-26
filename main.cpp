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
