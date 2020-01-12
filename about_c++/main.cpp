#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> graph[1001]; //c++ 동적으로 변수 안됨
int node, edge, answer = 0;
bool visited[1001];


void dfs(int start) {
    visited[start] = 0;

    for(int y : graph[start]){
        if(!visited[y]) dfs(y);
    }
}

int main() {
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int head, tail;
        cin >> head >> tail;
        graph[head].push_back(tail);
        graph[tail].push_back(head);
    }

    for (int i = 1; i <= node; i++) {
        sort(graph[i].begin(), graph[i].begin());
    }

    for (int i = 1; i <= node; i++) {
        visited[i] = false;
    }


    for (int i = 1; i <= node; i++) {
        if(!visited[i]){
            dfs(i);
            answer++;
        }
    }
    cout<<answer;


}