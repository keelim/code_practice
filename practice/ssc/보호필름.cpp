#include<iostream>
#include<cstring>

using namespace std;

int n, m, K, answer;
int map[20][20];
int cmap[20][20];
bool sel[20];

bool check(int ref[][20]) {
    for (int i = 0; i < m; i++) {
        int aCnt = 0;
        int bCnt = 0;
        bool flag = false;

        for (int j = 0; j < n; j++) {
            if (ref[j][i] == 0) {
                bCnt = 0;
                aCnt += 1;
            } else {
                aCnt = 0;
                bCnt += 1;
            }

            if (aCnt == K || bCnt == K) {
                flag = true;
                break;
            }
        }

        if (!flag) return false;
    }
    return true;
}

void makeVisit(int index, int value, bool flag) {
    if (flag) {
        for (int i = 0; i < m; i++) cmap[index][i] = value;
    } else {
        for (int i = 0; i < m; i++) cmap[index][i] = map[index][i];
    }
}

void go(int index, int cnt) {
    if (cnt > K || cnt >= answer) return; // 종료 조건

    if (check(cmap)) {
        answer = min(answer, cnt);
        return;
    }

    for (int i = index; i < n; i++) {
        if (sel[i] == true) continue;
        sel[i] = true;

        for (int j = 0; j < 2; j++) {
            makeVisit(i, j, true);
            go(i, cnt + 1);
            makeVisit(i, j, false);
        }
        sel[i] = false;
    }
}


int main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        answer = 987654321;
        memset(sel, false, sizeof(sel));

        cin >> n >> m >> K;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                cmap[i][j] = map[i][j];
            }
        }

        if (check(map) || K == 1) {
            answer = 0;
            return 0;
        }

        go(0, 0);

        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}
