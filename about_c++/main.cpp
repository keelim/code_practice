#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vc;

int dx[] = {-1, 1, 0, 0}; //x 방향
int dy[] = {0, 0, -1, 1}; //y 방향
int n;
int graph[26][26];
int room = 0; // 값

// dfs 정의
void dfs(int i, int j) { // room 숫자를 세는 것
    graph[i][j] = 0; //방문한 곳을 0으로 바꾸는 거네
    room++;
    for (int k = 0; k < 4; k++) {
        if (i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= n) continue; //범위 체크
        if (graph[i + dy[k]][j + dx[k]] == 1) { //근처 방을 탐색을 하는 것
            dfs(i + dy[k], j + dx[k]);
        }
    }
}

// int main() {
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%1d", &graph[i][j]); //그래프 초기화
//         }
//     }


//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (graph[i][j] == 1) {
//                 room = 0;
//                 dfs(i, j);
//                 vc.push_back(room);
//             }
//         }
//     }

//     sort(vc.begin(), vc.end());
//     cout << vc.size() << "\n";

//     for (int i : vc) {
//         cout << i << "\n";
//     }

// }

void dfs(int i, int j){
    
}
