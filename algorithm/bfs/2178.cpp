<<<<<<< HEAD
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

=======
#include<iostream>
#include<queue>

using namespace std;

#define MAX 1001

int n, m;
int cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1 , -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue <pair <pair<int, int>, int>> q;



int main() {
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				visited[i][j] = true;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)	continue;
			if (map[nx][ny] == 0 && !visited[nx][ny]) {
				
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				cnt = -1; break;
			}
		}
	}

	cout << cnt;
	return 0;
>>>>>>> e782372d2c0c4e87c143f9305c7904f06b0a1f99
}