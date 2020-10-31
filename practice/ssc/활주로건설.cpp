#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int testcase;
int n, x, answer;
int map[21][21];
bool visited[2][21][21];

void checkRow() {
    for (int j = 0; j < n; j++) {
        bool possible = true;

        for (int i = 0; i < n - 1; i++) {
            int u = map[i][j];
            int d = map[i + 1][j];
            int dif = abs(u - d);

            // 지형의 높이가 같다면
            if (dif == 0) continue;

            // 높이 차가 1보다 크다면
            if (dif > 1) {
                possible = false;
                break;
            }

            // 아래쪽에 설치
            if (u > d) {
                // 경사로 설치 가능 확인
                for (int k = i + 1; k <= i + x; k++) {
                    // 범위를 벗어났거나 이미 방문했거나 값이 다르면
                    if (k >= n || visited[0][k][j] || map[k][j] != d) {
                        possible = false;
                        break;
                    }
                }

                // 경사로 설치
                if (possible) {
                    for (int k = i + 1; k <= i + x; k++) {
                        visited[0][k][j] = true;
                    }
                }
            }
                // 위쪽에 설치
            else if (u < d) {
                // 경사로 설치 가능 확인
                for (int k = i - 1; k > i - x; k--) {
                    // 범위를 벗어났거나 이미 방문했거나 값이 다르면
                    if (k < 0 || visited[0][k][j] || map[k][j] != u) {
                        possible = false;
                        break;
                    }
                }

                // 경사로 설치
                if (possible) {
                    for (int k = i - 1; k > i - x; k--) {
                        visited[0][k][j] = true;
                    }
                }
            }

        }

        if (possible) answer += 1;
    }
}

void checkCol() {
    for (int i = 0; i < n; i++) {
        bool possible = true;

        for (int j = 0; j < n - 1; j++) {
            int l = map[i][j];
            int r = map[i][j + 1];
            int dif = abs(l - r);

            // 지형의 높이가 같다면
            if (dif == 0) continue;

            // 높이 차가 1보다 크다면
            if (dif > 1) {
                possible = false;
                break;
            }

            // 오른쪽에 설치
            if (l > r) {
                // 경사로 설치 가능 확인
                for (int k = j + 1; k <= j + x; k++) {
                    // 범위를 벗어났거나 이미 방문했거나 값이 다르면
                    if (k >= n || visited[1][i][k] || map[i][k] != r) {
                        possible = false;
                        break;
                    }
                }

                // 경사로 설치
                for (int k = j + 1; k <= j + x; k++) {
                    visited[1][i][k] = true;
                }
            }
                // 왼쪽에 설치
            else if (l < r) {
                // 경사로 설치 가능 확인
                for (int k = j - 1; k > j - x; k--) {
                    // 범위를 벗어났거나 이미 방문했거나 값이 다르면
                    if (k >= n || visited[1][i][k] || map[i][k] != l) {
                        possible = false;
                        break;
                    }
                }

                // 경사로 설치
                for (int k = j - 1; k > j - x; k--) {
                    visited[1][i][k] = true;
                }
            }
        }

        if (possible) answer++;
    }
}

int main() {

    cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        cin >> n >> x;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        answer = 0;
        memset(visited, false, sizeof(visited));
        
        checkRow();
        checkCol();

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}