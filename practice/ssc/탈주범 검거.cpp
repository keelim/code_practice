#include<iostream>
#include<cstring>
#include<queue>
#include <tuple>

#define endl "\n"
#define MAX 50
using namespace std;

int n, m, r, c, l, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool pipeDir[8][4];
bool connect[8][8][4];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Setting() {
    /*
    미리 설정하는 단계.
    pipeDir[a][b] = true - a도형에서 b방향으로 움직일 수 있습니다.
    connect[a][b][c] = true - a도형에서 b도형으로 c방향으로 움직일 수 있습니다.

    이 부분은 모든 TestCase에 대해서 공통적인 부분이기 때문에, 각 테스트케이스 마다 호출되는것이 아닌
    프로그램 시작과 동시에 1번만 호출시키도록 구현해놨음.
    */
    pipeDir[1][0] = pipeDir[1][1] = pipeDir[1][2] = pipeDir[1][3] = true;
    pipeDir[2][2] = pipeDir[2][3] = true;
    pipeDir[3][0] = pipeDir[3][1] = true;
    pipeDir[4][0] = pipeDir[4][3] = true;
    pipeDir[5][0] = pipeDir[5][2] = true;
    pipeDir[6][1] = pipeDir[6][2] = true;
    pipeDir[7][1] = pipeDir[7][3] = true;

    connect[1][1][0] = connect[1][1][1] = connect[1][1][2] = connect[1][1][3] = true;
    connect[1][2][2] = connect[1][2][3] = connect[1][3][0] = connect[1][3][1] = true;
    connect[1][4][2] = connect[1][4][1] = connect[1][5][1] = connect[1][5][3] = true;
    connect[1][6][0] = connect[1][6][3] = connect[1][7][2] = connect[1][7][0] = true;
    connect[2][1][3] = connect[2][1][2] = connect[2][2][2] = connect[2][2][3] = true;
    connect[2][4][2] = connect[2][5][3] = connect[2][6][3] = connect[2][7][2] = true;
    connect[3][1][0] = connect[3][1][1] = connect[3][3][0] = connect[3][3][1] = true;
    connect[3][4][1] = connect[3][5][1] = connect[3][6][0] = connect[3][7][0] = true;
    connect[4][1][3] = connect[4][1][0] = connect[4][2][3] = connect[4][3][0] = true;
    connect[4][5][3] = connect[4][6][0] = connect[4][6][3] = connect[4][7][0] = true;
    connect[5][1][0] = connect[5][1][2] = connect[5][2][2] = connect[5][3][0] = true;
    connect[5][4][2] = connect[5][6][0] = connect[5][7][0] = connect[5][7][2] = true;
    connect[6][1][1] = connect[6][1][2] = connect[6][2][2] = connect[6][3][1] = true;
    connect[6][4][1] = connect[6][4][2] = connect[6][5][1] = connect[6][7][2] = true;
    connect[7][1][1] = connect[7][1][3] = connect[7][2][3] = connect[7][3][1] = true;
    connect[7][4][1] = connect[7][5][1] = connect[7][5][3] = connect[7][6][3] = true;
}

void Initialize() {
    answer = 0;
    memset(visited, false, sizeof(visited));
}

void Input() {
    cin >> n >> m >> r >> c >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}


void Solution() {
    queue<tuple<int, int, int>> q;
    q.push({r, c, 1});
    visited[r][c] = true;
    answer += 1;

    while (q.empty() == 0) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        int shape = map[x][y];
        q.pop();

        if (cnt == l) continue; // 넘기는 조건

        for (int i = 0; i < 4; i++) {
            if (pipeDir[shape][i] == true) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if (!visited[nx][ny] && map[nx][ny] == 0) {
                    int nShape = map[nx][ny];
                    if (connect[shape][nShape][i] == true) {
                        q.push({nx, ny, cnt + 1});
                        visited[nx][ny] = true;
                        answer+=1;
                    }
                }
            }
        }
    }
}


int main(void) {
    Setting();            // 테스트 케이스가 돌기 전에 1번만 실행.
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
