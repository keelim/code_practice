#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include <tuple>
#define endl "\n"
#define MAX 8
using namespace std;

bool already;
int answer, N, K;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<pair<int, int>> V_Max;

int Max, min_val;

void Initialize() {
    answer = 0;
    already = true;
    Max = 0;
    min_val = 987654321;
    memset(visited, false, sizeof(visited));
    memset(map, 0, sizeof(map));
    V_Max.clear();
}

void Input() {

    int Num = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (i == 0 && j == 0) Num = map[i][j];
            else {
                if (already == true) {
                    if (map[i][j] != Num) already = false;
                }
            }

            if (map[i][j] > Max) Max = map[i][j];
            if (map[i][j] < min_val) min_val = map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == Max) V_Max.push_back(make_pair(i, j));
        }
    }
}

void BFS(int a, int b, int A[][MAX]) {
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 1));
    visited[a][b] = true;

    int Cnt;

    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        Cnt = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (visited[nx][ny] == false && A[nx][ny] < A[x][y]) {
                    visited[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                }
            }
        }
    }
    answer = max(answer, Cnt);
}

void DFS(int x, int y, int len, int A[][MAX]) {
    answer = max(answer, len);

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if (!visited[nx][ny] && A[nx][ny] < A[x][y]) {
            DFS(nx, ny, len + 1, A);
        }
    }
    visited[x][y] = false;
}

void Solution() {
    if (already == true) {
        answer = 2;
        return;
    }

    for (int i = 0; i < V_Max.size(); i++) {
        int x, y;
        tie(x,y) = V_Max[i];
        DFS(x, y, 1, map);
    }

    for (int k = 0; k < V_Max.size(); k++) {
        int x, y;
        tie(x,y) = V_Max[k];

        int cmap[MAX][MAX];
        memcpy(cmap, map, sizeof(map));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == min_val) continue;
                if (i == x && j == y) continue;

                for (int t = 1; t <= K; t++) {
                    cmap[i][j] = cmap[i][j] - t;
                    DFS(x, y, 1, cmap);
                    cmap[i][j] = cmap[i][j] + t;
                }
            }
        }
    }
}


int main(void) {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        Initialize();
        Input();
        Solution();

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}
