#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int testcase;
int n, r, c, answer;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> map;

vector<vector<int>> bombBlock(vector<vector<int>> v, int col) {
    // 구슬이 명중하는 노드 찾기
    int row = -1;
    for (int i = r - 1; i >= 0; i--) {
        if (v[i][col] == 0) {
            row = i;
            break;
        }
    }

    if (row == r - 1) return v;
    else if (row == -1) row = 0;
    else row += 1;


    queue<tuple<int, int, int>> q;
    q.emplace(row, col, v[row][col]);
    v[row][col] = 0;

    while (!q.empty()) {
        int x, y, range;
        tie(x, y, range) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x;
            int ny = y;
            for (int j = 1; j < range; j++) {
                nx += dx[i];
                ny += dy[i];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

                if (v[nx][ny] >= 1) {
                    q.emplace(nx, ny, v[nx][ny]);
                    v[nx][ny] = 0;
                }
            }
        }
    }

    return v;
}

vector<vector<int>> downBlock(vector<vector<int>> v) {
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] != 0) {
                int row = i;
                int col = j;

                while (1) {
                    if (v[row + 1][col] != 0 || row + 1 >= r) break;

                    v[row + 1][col] = v[row][col];
                    v[row][col] = 0;
                    row++;
                }
            }
        }
    }

    return v;
}

int getBlock(vector<vector<int>> v) {
    int res = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] != 0) res += 1;
        }
    }

    return res;
}

void dfs(vector<vector<int>> v, int cnt) {
    // n개의 구술을 쐈다면
    if (cnt == n) {
        answer = min(answer, getBlock(v));
        return;
    }

    for (int i = 0; i < c; i++) {
        vector<vector<int>> temp = bombBlock(v, i);
        temp = downBlock(temp);
        dfs(temp, cnt + 1);
    }
}

int main() {
    cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        cin >> n >> c >> r;

        map.clear();
        map = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> map[i][j];
            }
        }

        answer = 987654321;
        dfs(map, 0);

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}