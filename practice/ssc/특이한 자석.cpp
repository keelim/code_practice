#include <iostream>
#include <algorithm>

using namespace std;

int testcase;
int k, index, dir, answer, sum;
int map[5][9];

void rotateMagnet(int i, int d) {
    // 시계 방향 회전
    if (d == 1) {
        int tmp = map[i][8];
        for (int j = 8; j >= 2; j--) {
            map[i][j] = map[i][j - 1];
        }
        map[i][1] = tmp;
    }
        // 반시계 방향 회전
    else {
        int tmp = map[i][1];
        for (int j = 1; j <= 7; j++) {
            map[i][j] = map[i][j + 1];
        }
        map[i][8] = tmp;
    }
}

void go() { // 재귀
    // 현재 자석 정보
    int leftValue = map[index][7];
    int rightValue = map[index][3];

    // 해당 자석 회전
    rotateMagnet(index, dir);

    // 왼쪽 회전
    int d = dir;
    for (int i = index - 1; i >= 1; i--) {
        if (leftValue != map[i][3]) {
            d *= -1;
            leftValue = map[i][7];
            rotateMagnet(i, d);
        } else {
            break;
        }
    }

    // 오른쪽 회전
    d = dir;
    for (int i = index + 1; i <= 4; i++) {
        if (rightValue != map[i][7]) {
            d *= -1;
            rightValue = map[i][3];
            rotateMagnet(i, d);
        } else {
            break;
        }
    }
}

int main() {

    cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        cin >> k;

        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 8; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < k; i++) {
            cin >> index >> dir;
            go();
        }

        answer = 0;
        sum = 1;
        for (int i = 1; i <= 4; i++) {
            if (map[i][1] == 1) {
                answer += sum;
            }
            sum *= 2;
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}