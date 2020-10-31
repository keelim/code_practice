#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define endl "\n"
#define MAX 350
#define SIZE 150
using namespace std;

typedef struct {
    int x;
    int y;
    int Born_Time;
    int Life_Value;
    int dieTime;
    int Active_Time;
    bool state;
} cell;

int n, m, k;
int answer;
int map[MAX][MAX];
vector<cell> vc;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void init() {
    memset(map, 0, sizeof(map));
    vc.clear();
    answer = 0;
}

bool Standard(cell A, cell B) {
    if (A.Life_Value > B.Life_Value) return true;
    return false;
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a == 0) continue;

            map[i + SIZE][j + SIZE] = a;

            cell temp;
            temp.x = i + SIZE;
            temp.y = j + SIZE;
            temp.state = true;
            temp.Life_Value = a;
            temp.Born_Time = 0;
            temp.Active_Time = temp.Born_Time + temp.Life_Value;
            temp.dieTime = temp.Active_Time * 2;
            vc.push_back(temp);
        }
    }
}

void die(int T) {
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i].dieTime == T) {
            vc[i].state = false;
        }
    }
}

void active(int T) {
    vector<cell> temp;
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i].state == false) continue;
        if (vc[i].Active_Time == T) {

            int x = vc[i].x;
            int y = vc[i].y;
            int Lv = vc[i].Life_Value;

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (map[nx][ny] != 0) continue;

                cell Temp;
                Temp.x = nx;
                Temp.y = ny;
                Temp.Life_Value = Lv;
                Temp.state = true;
                Temp.Born_Time = T + 1;
                Temp.Active_Time = Temp.Born_Time + Temp.Life_Value;
                Temp.dieTime = Temp.Active_Time + Temp.Life_Value;

                temp.push_back(Temp);
            }
        }
    }

    if (temp.size() == 0) return;
    sort(temp.begin(), temp.end(), Standard);

    for (int i = 0; i < temp.size(); i++) {
        int x = temp[i].x;
        int y = temp[i].y;
        int Lv = temp[i].Life_Value;

        if (map[x][y] != 0) continue;
        map[x][y] = Lv;
        vc.push_back(temp[i]);
    }
}

void solution() {
    int time = 0;
    while (1) {
        if (time == k) break;
        die(time);
        active(time);
        time += 1;
    }

    int cnt = 0;
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i].state == false) cnt += 1;
        if (vc[i].dieTime == k) cnt += 1;
        if (vc[i].Born_Time == k + 1) cnt += 1;
    }

    answer = vc.size() - cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        Initialize();
        Input();
        solution();

        cout << "#" << t << " " << answer << endl;
    }

    return 0;
}
