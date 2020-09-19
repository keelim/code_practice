#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
char map[251][251];
bool visited[251][251];

pair<int, int> bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    int c = 0;
    int d = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (!visited[nx][ny] && map[nx][ny] != '#') {
                if (map[nx][ny] == 'v') {
                    d++;
                } else if (map[nx][ny] == 'k') {
                    c++;
                }
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }

    if(c>d){
        d=0;
    } else{
        c=0;
    }

    return make_pair(c, d);
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
        }
    } //input
    pair<int, int> answer = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pair<int, int> a = bfs(i, j);
            answer.first += a.first;
            answer.second += a.second;
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}