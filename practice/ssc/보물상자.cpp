#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, lnum, answer;
vector<char> vc[4];
vector<int> result;

void Initialize() {
    for (int i = 0; i < 4; i++) {
        vc[i].clear();
    }
    result.clear();
    answer = 0;
}

void Input() {
    cin >> n >> k;
    string input;
    cin >> input;
    lnum = n / 4;        // 한 변에 들어갈 수 있는 숫자의 갯수 파악
    int index = 0;
    int cnt = 0;

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];

        vc[index].push_back(c);    // 벡터 배열에 한 변에 들어갈 수 있는 숫자의 갯수만큼만 push.
        cnt += 1;

        if (cnt == lnum) {
            index += 1;
            cnt = 0;
        }
    }
}

void turn() {
    /* 보물 상자를 시계 방향으로 회전시켜 보는 함수. */
    char start = vc[0].at(0);
    char tail = vc[3][lnum - 1];

    /* 회전시키는 방법
       - 첫 번째 변의 첫 번째 값과 마지막 값까지 계속해서 Swap !
       - 결과적으로 한 칸씩 회전 시킨것과 같은 효과.
    */
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < lnum; j++) {
            swap(vc[0][0], vc[i][j]);
        }
    }
    vc[0][0] = tail;
}

bool findData(int d) {
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == d)
            return true;
    }
    return false;
}

void Calculate_Value() {
    /* 16진수를 10진수로 변환 및 각 변에 있는 값들을 계산해서 Vector에 저장해 주는 함수. */
    for (int i = 0; i < 4; i++) {
        /* 16진수를 10진수로 변환하는 과정 */
        int p = lnum - 1;
        int sum = 0;
        for (int j = 0; j < vc[i].size(); j++) {
            char c = vc[i].at(j);
            int temp;
            if ('0' <= c && c <= '9') temp = c - '0';

            else if ('A' <= c && c <= 'F') temp = (c - 'A') + 10;

            int Sixteen = 1;

            for (int k = 0; k < p; k++) Sixteen = Sixteen * 16;

            sum = sum + Sixteen * temp;
            p--;
        }

        /* 중복된 값이 없으면 나올 수 있는 숫자들을 Vector에 저장. */
        if (findData(sum) == false) result.push_back(sum);
    }
}

void Solution() {
    /* 보물 상자의 초기 상태에서의 값들부터 모두 Check. */
    Calculate_Value();

    for (int i = 0; i < lnum; i++) {
        turn();
        Calculate_Value();
    }

    sort(result.begin(), result.end(), greater<>());
    answer = result[k - 1];
}


int main() {
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        Initialize();
        Input();
        Solution();

        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}