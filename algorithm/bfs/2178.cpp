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
}