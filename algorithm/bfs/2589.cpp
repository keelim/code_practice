#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, m;
char m[51][51];
int visited[51][51];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int max = 0;
void bfs(pair<int, int> startp) {
    queue<pair<int, int> > q;
	q.push(startp);
	visited[startp.first][startp.second]++;
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] >= 0 || m[nr][nc] == 'W') continue;
			
			q.push({ nr, nc });
			visited[nr][nc] = visited[cur.first][cur.second] + 1;
			if (visited[nr][nc] > max) max = visited[nr][nc];
			
		}
	}
}
void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = -1;
}
int main(void) {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			m[i][j] = str[j];
			visited[i][j] = -1;
		}
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (m[i][j] == 'L') {
				bfs({ i, j });
				init();
			}
		}
	}
	cout << max;
	return 0;
}