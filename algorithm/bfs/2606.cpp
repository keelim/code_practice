#include <iostream>
#include <queue>

using namespace std;

int map[101][101]
bool visited[101];
in

int bfs(int a, int b, int count){
    queue<pair<pair<int, int>, int>> q;
    int cnt = count;

    q.push(make_pair(make_pair(a,b),cnt));
    

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        cnt = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){

        }
        
    }


}



int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x, y;

        cin>>x>>y;
        map[x][y] =1;
        map[y][x] = 1;
    
    } //input
    
    cout<<bfs(1, 1, 0);
    //bfs
    return 0;
}