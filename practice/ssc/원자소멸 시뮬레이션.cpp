#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

#define endl "\n"
#define MAX 4001
using namespace std;

typedef struct {
    int x;
    int y;
    int dir;
    int Energy;
    bool Live;
} atom_info;

int N, answer;
int map[MAX][MAX];
vector<atom_info> vc;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool die() {
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i].Live == true) return false;
    }
    return true;
}

void move() {
    while (1) {
        int value = 0;
        if (die()) break;

        for (int i = 0; i < vc.size(); i++) {
            if (vc[i].Live == false) continue;

            int x = vc[i].x;
            int y = vc[i].y;
            int dir = vc[i].dir;

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) { //  범위 안이면
                map[x][y] = 0;
                map[nx][ny] = map[nx][ny] + 1;
                x = nx;
                y = ny;
                vc[i].x = x;
                vc[i].y = y;
            } else {
                vc[i].Live = false;
                map[x][y] = 0;
            }
        }

        for (int i = 0; i < vc.size(); i++) {
            if (vc[i].Live == false) continue;
            int x = vc[i].x;
            int y = vc[i].y;

            if (map[x][y] >= 2)    // 한개라면 터지지는 않으니 최소 2개 이상이 만났을 때
            {
                for (int j = 0; j < vc.size(); j++) {
                    if (i == j) continue;
                    if (vc[j].Live == false) continue;

                    int xx = vc[j].x;
                    int yy = vc[j].y;

                    if (x == xx && y == yy) {
                        value = value + vc[j].Energy;
                        vc[j].Live = false;
                    }
                }

                value += vc[i].Energy;
                vc[i].Live = false;
                map[x][y] = 0;
            }

        }
        answer += value;
    }
}

int main(void) {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        N = 0;
        answer = 0;
        vc.clear();
        memset(map, 0, sizeof(map));

        cin >> N;
        for (int i = 0; i < N; i++) {
            int x, y, dir, k;
            cin >> x >> y >> dir >> k;
            x = (x + 1000) * 2;
            y = (y + 1000) * 2;
            atom_info temp;
            temp.x = x;
            temp.y = y;
            temp.dir = dir;
            temp.Energy = k;
            temp.Live = true;
            vc.push_back(temp);
            map[x][y] = 1;
        }

        if (vc.empty() || vc.size() == 1) {
            answer = 0;
            return 0;
        }

        move();

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}