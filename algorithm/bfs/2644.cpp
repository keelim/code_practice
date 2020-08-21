#include <iostream>
#include <queue>

int map[101][101];
bool visited[101];

int main(){
    int x, first, second, m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;

        map[a][b] = 1;
        map[b][a] = 1;
    }

    bfs(first)

}