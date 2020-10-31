#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
#define MAX 100
using namespace std;

typedef struct {
    int x;
    int y;
    int num;
    int dir;
    bool state;
} bug;

int answer;
int n, m, k;
vector<int> map[MAX][MAX];
vector<bug> vc;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void move() {
    for (int i = 0; i < vc.size(); i++) {
        if (!vc[i].state) continue;
        map[vc[i].x][vc[i].y].clear();
    }

    for (int i = 0; i < vc.size(); i++) {
        if (!vc[i].state) continue;

        vc[i].x = vc[i].x + dx[vc[i].dir];
        vc[i].y = vc[i].y + dy[vc[i].dir];
        map[vc[i].x][vc[i].y].push_back(i);
    }
}

int changeDirection(int direction) {
    if (direction == 1) return 2;
    else if (direction == 2) return 1;
    else if (direction == 3) return 4;
    else if (direction == 4) return 3;
}

void kill() {
    // Kill
    for (int i = 0; i < vc.size(); i++) {
        if (!vc[i].state) continue;

        int x = vc[i].x;
        int y = vc[i].y;
        int d = vc[i].dir;

        if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
            vc[i].num = vc[i].num / 2;
            vc[i].dir = changeDirection(d);
        }

        if (vc[i].num == 0) {
            vc[i].state = false;
        }
    }

    for (int i = 0; i < vc.size(); i++) {
        if (!vc[i].state) continue;

        int x = vc[i].x;
        int y = vc[i].y;

        if (map[x][y].size() > 1) {
            int Sum = 0;
            int Biggest_Num = 0;
            int Select_Dir = 0;
            int Select_Idx = 0;

            for (int j = 0; j < map[x][y].size(); j++) {
                Sum = Sum + vc[map[x][y][j]].num;
                if (vc[map[x][y][j]].num > Biggest_Num) {
                    Biggest_Num = vc[map[x][y][j]].num;
                    Select_Dir = vc[map[x][y][j]].dir;
                    Select_Idx = map[x][y][j];
                }
                vc[map[x][y][j]].state = false;
            }

            vc[Select_Idx].num = Sum;
            vc[Select_Idx].dir = Select_Dir;
            vc[Select_Idx].state = true;
            map[x][y].clear();
            map[x][y].push_back(Select_Idx);
        }
    }
}

int calc() {
    int sum = 0;
    for (int i = 0; i < vc.size(); i++) {
        if (!vc[i].state) continue;
        sum += vc[i].num;
    }
    return sum;
}

int main() {

    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        answer = 0;
        vc.clear();
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                map[i][j].clear();
            }
        }
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int x, y, n, d;
            cin >> x >> y >> n >> d;
            bug temp;
            temp.x = x;
            temp.y = y;
            temp.num = n;
            temp.dir = d;
            temp.state = true;
            vc.push_back(temp);
            map[x][y].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            move();
            kill();
        }

        answer = calc();

        cout << "#" << t << " " << answer << endl;
    }

    return 0;
}
