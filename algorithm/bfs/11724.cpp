#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> map[1001]; //c++ 동적으로 변수 안됨
bool visited[1001];

void dfs(int start) {
    visited[start] = true;
    for (int y : map[start]) {
        if (!visited[y]) dfs(y);
    }
}

int main() {
    int node, edge, answer;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int head, tail;
        cin >> head >> tail;
        map[head].push_back(tail);
        map[tail].push_back(head);
    }

    for (int i = 1; i <= node; i++) {
        sort(map[i].begin(), map[i].begin());
    }

    for (int i = 1; i <= node; i++) {
        visited[i] = false;
    }

    answer = 0;

    for (int i = 1; i <= node; i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }
    cout << answer;
}