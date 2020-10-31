#include<iostream>
#include<vector>
#include <tuple>

#define endl "\n"
#define MAX 100
using namespace std;

int answer;
int n;
int map[MAX][MAX];
bool already[5];
pair<pair<int, int>, pair<int, int>> warmHole[5];


vector<pair<int, int>> vc;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sx, sy;


void Initialize() {
    answer = 0;
    for (int i = 0; i < 5; i++) {
        warmHole[i].first.first = -1;
        warmHole[i].first.second = -1;
        warmHole[i].second.first = -1;
        warmHole[i].second.second = -1;
        already[i] = false;
    }
    vc.clear();
}

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                vc.emplace_back(i, j);
            } else if (6 <= map[i][j] && map[i][j] <= 10) {
                if (already[map[i][j] - 6] == false) {
                    warmHole[map[i][j] - 6].first.first = i;
                    warmHole[map[i][j] - 6].first.second = j;
                    already[map[i][j] - 6] = true;
                } else {
                    warmHole[map[i][j] - 6].second.first = i;
                    warmHole[map[i][j] - 6].second.second = j;
                }
            }
        }
    }
}

int changeDir(int dir, int shape) {
    int nd;
    if (dir == 0) {
        if (shape == 1 || shape == 2 || shape == 5) nd = 1;
        else if (shape == 3) nd = 2;
        else nd = 3;
    } else if (dir == 1) {
        if (shape == 3 || shape == 4 || shape == 5) nd = 0;
        else if (shape == 1) nd = 3;
        else nd = 2;
    } else if (dir == 2) {
        if (shape == 2 || shape == 3 || shape == 5) nd = 3;
        else if (shape == 1) nd = 0;
        else nd = 1;
    } else {
        if (shape == 1 || shape == 4 || shape == 5) nd = nd = 2;
        else if (shape == 2) nd = 0;
        else nd = 1;
    }
    return nd;
}

int move(int x, int y, int d) {
    int score = 0;
    while (1) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nd = d;

        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (map[nx][ny] == -1 || (nx == sx && ny == sy)) break;

            else if (1 <= map[nx][ny] && map[nx][ny] <= 5) {
                nd = changeDir(d, map[nx][ny]);
                score += 1;

            } else if (6 <= map[nx][ny] && map[nx][ny] <= 10) {
                if (nx == warmHole[map[nx][ny] - 6].first.first && ny == warmHole[map[nx][ny] - 6].first.second) {
                    int tx = warmHole[map[nx][ny] - 6].second.first;
                    int ty = warmHole[map[nx][ny] - 6].second.second;
                    nx = tx;
                    ny = ty;
                } else {
                    int tx = warmHole[map[nx][ny] - 6].first.first;
                    int ty = warmHole[map[nx][ny] - 6].first.second;
                    nx = tx;
                    ny = ty;
                }
            }
        } else {
            if (d == 0) nd = 1;
            else if (d == 1) nd = 0;
            else if (d == 2) nd = 3;
            else if (d == 3) nd = 2;
            score += 1;
        }
        x = nx;
        y = ny;
        d = nd;
    }
    return score;
}

void Solution() {
    for (int i = 0; i < vc.size(); i++) {
        int x, y;
        tie(x, y) = vc[i];
        sx = x;
        sy = y;

        for (int j = 0; j < 4; j++) {
            int temp = move(x, y, j);
            answer = max(answer, temp);
        }
    }
}

int main() {
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