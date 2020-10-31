#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int n, m, answer;
int map[20][20];
bool visited[20][20];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int calc(int k) {
    return (k * k) + (k - 1) * (k - 1);
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = true;
    int cnt = 0;

    if (map[a][b] == 1) cnt += 1;
    int service = 1;

    while (!q.empty()) {
        if (service > n + 1)
            break;
        if (cnt * m - calc(service) >= 0) {
            answer = max(answer, cnt);
        }

        int size = q.size(); // 턴마다 처리를 해야 한다.
        for (int qs = 0; qs < size; qs++) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 체크
                if (!visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    if (map[nx][ny] == 1) {
                        cnt += 1;
                    }
                }
            }
        }
        service += 1;
    }
}

int main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        answer = 0;
        memset(map, 0, sizeof(map));

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memset(visited, false, sizeof(visited));
                bfs(i, j);
            }
        }

        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}