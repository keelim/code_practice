#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100000;
bool visited[MAX];
bool visited1[MAX];
vector<int> graph[MAX];
queue<int> Q;

void dfs(int start) {
    visited[start] = true;
    cout << start << " ";
    for (int y : graph[start]) {
        if (!visited[y]) {
            dfs(y);
        }
    }
}

void bfs(int start) {
    visited1[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int element = Q.front();
        cout << element << " ";
        Q.pop();
        for (int y: graph[element]) {
            if (!visited1[y]) {
                visited1[y] = true;
                Q.push(y);
            }
        }
    }
}

int main() {
    int node, edge, start;
    cin >> node >> edge >> start;
    for (int i = 0; i < node; i++) {
        int head, tail;
        cin >> head >> tail;
        graph[head].push_back(tail);
        graph[tail].push_back(head);
    }

    for (int i = 1; i <= node; i++) { //모든 노드 정렬
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    cout << "\n";

    bfs(start);
    cout << "\n";

}