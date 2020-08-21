/* 7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
7
8
9 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> vc;

int map[26][26];
bool visited[26][26];


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||ny<0||nx>=n||ny>=n) continue;

            if(!visited[nx][ny]&&map[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char cs[n];        cin >> cs;
        for (int j = 0; j < n; j++)
            map[i][j] = cs[j] - '0';
    } //input

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&map[i][j]){
                cnt++;
                int value = bfs(i, j);
                vc.push_back(value);
            }
        }
    }

    sort(vc.begin(), vc.end());

    cout<<cnt<<endl;
    for(int i=0; i<vc.size(); i++){
        cout<<vc[i]<<endl;
    }

    return 0;
}
