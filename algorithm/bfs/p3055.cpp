#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char map[51][51];
int wmap[51][51] = {-1, };
bool visited [51][51];
int dx[4] = {1, -1 ,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int, int>> wq;

int main(){ //* 물 //X 돌 // D 둥 S 시작 
    cin>>n>>m;
    pair<int, int> start, end;

    for(int i=0; i<n; i++)    {
        for(int j=0; j<m; j++){
            char pointer;
            cin>>pointer;
            map[i][j] = pointer;

            if(pointer == 'S') start = make_pair(i, j);
            if(pointer == 'D') end = make_pair(i, j);
            if(pointer == '*'){
                wmap[i][j] = 0;
                wq.push(make_pair(i, j));
            }

        }
    }

    // make water map

    while (!wq.empty())
    {
        int x, y;
        tie(x, y) = wq.front();
        wq.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;

            if(map[nx][ny]=='.'&&wmap[nx][ny]>wmap[x][y]+1){
                wmap[nx][ny] = wmap[x][y]+1;
                wq.push(make_pair(x, y));
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = 1;
    int answer =1;

    while(!q.empty()){
        int x, y, count;
        tie(x, y, count) = q.front();
        q.pop();

        if (x == end.first && y == end.second)
        {
            cout << count<< endl;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[4];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;

            if(!visited[nx][ny]&&map[nx][ny]!='X'&&wmap[nx][ny]>count+1){
                visited[nx][ny] =1;
                q.push(make_tuple(nx, ny, count+1));
            }


        }
    }
    cout<<"KAKTUS"<<endl;


    

    //input
}