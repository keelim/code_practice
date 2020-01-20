#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0; // 값
bool visited[101];
vector<int> graph[101];

void dfs(int start){
    if(visited[start]) return;

    visited[start] = true;
    answer++;
    for(int y : graph[start]){
        if(!visited[y]) dfs(y);
    }
}

int main()
{
    int node, edge, start = 1;
    cin >> node >> edge;


    for (auto i = 0; i < edge; i++)
    {
        int head, tail;
        cin >> head >> tail;
        graph[head].push_back(tail);
        graph[tail].push_back(head);
    }

    for (auto i = 1; i <= node; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(start);
    cout<<answer-1;
}