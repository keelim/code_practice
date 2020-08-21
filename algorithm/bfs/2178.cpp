/* 4 6
101111
101010
101011
111011

15 */

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[101][101];
int visited[101][101];

int n, m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int a, int b){
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(a, b, 1));
    visited[a][b]=1;
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());

        if(x==n-1&&y==m-1){
            cout<<visited[x][y]<<endl;
            return ;
        }

        for(int i=0; i<4; i++){
            int nx =x+dx[i];
            int ny = y+dy[i];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;

            if(visited[nx][ny]==0&&map[nx][ny]){
                q.push(make_tuple(nx, ny, cnt+1));
                visited[nx][ny] = cnt+1;
            }
        }

    }
    
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        char cs[m];
        cin >> cs;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = cs[j] - '0';
        }
    } //input

    bfs(0,0);

}