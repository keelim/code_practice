#include <iostream>
#include <queue>

using namespace std;

int map[1000001];
bool visited[1000001];
int f, s, g, u, d;
queue<int> q;

int bfs(){ //c최단 값은 q에?

    //s->g
    int count =0;
    visited[s] = 1;
    q.push(s);

    while(!q.empty()){
        int floor = q.front();
        if(floor == g) return count;
        int nx;
        if(floor<g){
            nx = floor+u;
            if(nx>f) nx = floor-d;
        }  else if(floor>g) nx = floor-d;

        q.push(nx);
        count++;
    }
    return -1;
}

int main(){
    cin>>f>>s>>g>>u>>d;
    int answer = bfs();
    if(answer ==-1) cout<<"use the stairs";
    else cout<<answer;
}