#include<iostream>
#include<cstring>

#define endl "\n"
#define MAX 20
using namespace std;

int n, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool numVisited[101];

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};


void init() {
    answer = -1;
    memset(visited, false, sizeof(visited));
    memset(numVisited, false, sizeof(numVisited));
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
}

void dfs(int x, int y, int dir, int line, int cnt, int Sx, int Sy) {
    if (line > 4) return;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if (visited[nx][ny] == true) {
            if (line >= 3 && cnt >= 4 && nx == Sx && ny == Sy) {
                answer = max(answer, cnt);
                return;
            }
        } else {
            if (numVisited[map[nx][ny]] == false) {
                visited[nx][ny] = true;
                numVisited[map[nx][ny]] = true;

                if (dir == i)
                    dfs(nx, ny, i, line, cnt + 1, Sx, Sy);
                else
                    dfs(nx, ny, i, line + 1, cnt + 1, Sx, Sy);

                visited[nx][ny] = false;
                numVisited[map[nx][ny]] = false;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            visited[i][j] = true;
            numVisited[map[i][j]] = true;

            int nx = i + dx[3];
            int ny = j + dy[3];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (numVisited[map[nx][ny]] == false) {
                    numVisited[map[nx][ny]] = true;
                    visited[nx][ny] = true;
                    dfs(nx, ny, 3, 1, 2, i, j);
                    visited[nx][ny] = false;
                    numVisited[map[nx][ny]] = false;
                }
            }

            visited[i][j] = false;
            numVisited[map[i][j]] = false;
        }
    }
}


int main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        init();
        input();
        solve();

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}
