#include<iostream>
#include<vector>
#include<cmath>

#define endl "\n"
#define BCMAX 8
using namespace std;

typedef struct {
    int x;
    int y;
    int C;
    int P;
} Battery;

int answer, M, BC_Num;
vector<int> aMove, bMove;
vector<Battery> B;

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};

void Initialize() {
    answer = 0;
    aMove.clear();
    bMove.clear();
    B.clear();
    M = BC_Num = 0;
}

void Input() {
    cin >> M >> BC_Num;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        aMove.push_back(a);
    }
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        bMove.push_back(a);
    }
    for (int i = 0; i < BC_Num; i++) {
        int x, y, C, P;
        cin >> x >> y >> C >> P;
        x = x - 1;
        y = y - 1;

        Battery Temp;
        Temp.x = y;
        Temp.y = x;
        Temp.C = C;
        Temp.P = P;

        B.push_back(Temp);
    }
}

int Dist(int x, int y, int xx, int yy) {
    return (abs(x - xx) + abs(y - yy));
}

int Charging(int ax, int ay, int bx, int by) {
    vector<int> A_Use, B_Use;
    int A_Max = 0;
    int B_Max = 0;

    for (int i = 0; i < BC_Num; i++) {
        int x = B[i].x;
        int y = B[i].y;

        int A_Dist = Dist(ax, ay, x, y);    // 거리 내라면
        int B_Dist = Dist(bx, by, x, y);

        if (A_Dist <= B[i].C) {
            A_Use.push_back(i);
            A_Max = max(A_Max, B[i].P);
        }
        if (B_Dist <= B[i].C) {
            B_Use.push_back(i);
            B_Max = max(B_Max, B[i].P);
        }
    }

    if (A_Use.empty()) {
        if (B_Use.empty()) return 0;
        else return B_Max;
    }

    if (B_Use.empty()) {
        if (A_Use.empty()) return 0;
        else return A_Max;
    }

    int Max_Energy = 0;

    for (int i = 0; i < A_Use.size(); i++) {
        int A_BC = A_Use[i];
        for (int j = 0; j < B_Use.size(); j++) {
            int B_BC = B_Use[j];

            if (A_BC == B_BC) Max_Energy = max(Max_Energy, B[A_BC].P);
            else Max_Energy = max(Max_Energy, B[A_BC].P + B[B_BC].P);
        }
    }
    return Max_Energy;
}

void Solution() {
    int ax, ay, bx, by;
    ax = ay = 0;
    bx = by = 9;
    answer = answer + Charging(ax, ay, bx, by);

    for (int i = 0; i < M; i++) {
        ax = ax + dx[aMove[i]];
        ay = ay + dy[aMove[i]];
        bx = bx + dx[bMove[i]];
        by = by + dy[bMove[i]];
        answer = answer + Charging(ax, ay, bx, by);
    }
}

int main(void) {
    int testcase;
    cin >> testcase;
    for (int T = 1; T <= testcase; T++) {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << answer << endl;
    }

    
    return 0;
}
