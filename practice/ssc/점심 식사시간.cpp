#include<iostream>
#include<cmath>
#include<queue>

#define endl "\n"
#define MAX 10
using namespace std;

struct STAIR        // 계단 구조체
{
    int x;            // x좌표
    int y;            // y좌표
    int Len;        // 계단의 길이
    int Num;        // 현재 이용자 수
};

struct PERSON        // 사람 구조체
{
    int x;            // x좌표
    int y;            // y좌표
    int MoveTime;    // 계단까지 가는데 걸리는 시간
    int StartTime;    // 계단을 이용하기 시작하는 시간
    int EndTime;    // 계단 이용을 끝내는 시간
    bool Finish;    // 계단을 모두 내려갔는지 Check.
};

int N, p, answer;
int MAP[MAX][MAX], sel[MAX];
PERSON person[MAX];            // '사람' 구조체 배열
STAIR Stair[2];                // '계단' 구조체 배열
queue<int> Waiting[2];        // 2개의 계단에서 대기열 역할을 해주는 Queue.

void Init() {
    for (int i = 0; i < p; i++) {
        person[i].MoveTime = person[i].StartTime = person[i].EndTime = -1;
        person[i].Finish = false;
    }
    for (int i = 0; i < 2; i++) {
        while (Waiting[i].empty() == 0) Waiting[i].pop();
        Stair[i].Num = 0;
    }
}

void input() {
    int P_Idx, Idx;
    P_Idx = Idx = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) {
                person[P_Idx].x = i;
                person[P_Idx].y = j;
                person[P_Idx].MoveTime = person[P_Idx].StartTime = person[P_Idx].EndTime = -1;
                person[P_Idx].Finish = false;
                P_Idx++;
            } else if (MAP[i][j] >= 2) {
                Stair[Idx].x = i;
                Stair[Idx].y = j;
                Stair[Idx].Len = MAP[i][j];
                Stair[Idx].Num = 0;
                Idx++;
            }
        }
    }
    p = P_Idx;
}

int dist(int P_Idx, int S_Idx) {
    int dx = abs(person[P_Idx].x - Stair[S_Idx].x);
    int dy = abs(person[P_Idx].y - Stair[S_Idx].y);
    return (dx + dy) + 1;
}

void CompleteMoving(int Time) {
    /*
    계단을 모두 내려간 사람들을 체크해주는 함수.
    * 내려간 사람의 Finish를 'true'로 설정.
    * 계단의 이용자수를 -1.
    */
    for (int i = 0; i < p; i++) {
        if (person[i].EndTime == Time) {
            person[i].Finish = true;
            Stair[sel[i]].Num--;
        }
    }
}

bool Check() {
    /* 무한루프의 종료조건을 위한 Check 함수. */
    for (int i = 0; i < p; i++) {
        if (person[i].Finish == false) return false;
    }
    return true;
}

void GoToStairs(int Time) {
    /* 현재 'Time'초에 계단에 도착하는 사람을 계단의 대기열에 넣어주는 함수. */
    for (int i = 0; i < p; i++) {
        if (person[i].MoveTime == Time) {
            int Idx = sel[i];
            Waiting[Idx].push(i);
        }
    }
}

void simulation() {
    /* Simulation 하는 함수. */
    /* 가장 먼저, 사람과 그 사람이 선택한 계단과의 거리를 구해준다. */
    for (int i = 0; i < p; i++) {
        person[i].MoveTime = dist(i, sel[i]);
    }

    int time = 0;
    while (1) {
        CompleteMoving(time);
        if (Check() == true) break;

        GoToStairs(time);

        for (int i = 0; i < 2; i++) {
            int Stair_Len = Stair[i].Num;
            int Wait_Len = Waiting[i].size();
            if (Stair_Len < 3 && Wait_Len > 0) {
                while (Waiting[i].empty() == 0) {
                    if (Stair[i].Num == 3) break;
                    person[Waiting[i].front()].StartTime = time;
                    person[Waiting[i].front()].EndTime = time + Stair[i].Len;
                    Stair[i].Num++;
                    Waiting[i].pop();
                }
            }
        }
        time++;
    }

    answer = min(answer, time);
}

void dfs(int cnt) {
    if (cnt == p) {
        /* 모든 사람이 계단 선택을 완료했을 경우 Simulation 시작. */
        Init();
        simulation();
        return;
    }

    for (int i = 0; i < 2; i++) { //중복 순열 구하기
        sel[cnt] = i;
        dfs(cnt + 1);
    }
}

void solution() {
    /* 중복 순열을 구하는 것으로 문제 풀이를 시작. */
    dfs(0);
}

int main(void) {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        answer = 987654321;
        input();
        solution();

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}