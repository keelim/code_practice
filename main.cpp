#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M, answer;
int map[101][101];
int dis[101][101];
bool visited[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void BFS(int a, int b) //여기 부터는 이해를 할 필요가 있다.
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	dis[a][b] = 0;

	while (Q.empty() == 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			if (map[nx][ny] == 1)
			{
				if (dis[nx][ny] > dis[x][y] + 1)
				{
					dis[nx][ny] = dis[x][y] + 1;
					Q.push(make_pair(nx, ny));
				}
			}
			else if (map[nx][ny] == 0)
			{
				if (dis[nx][ny] > dis[x][y])
				{
					dis[nx][ny] = dis[x][y];
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{

	answer = 987654321;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			map[i][j] = temp[j] - '0'; // 이것은 기억을 해둘 필요가 있다.
			dis[i][j] = 987654321;
		}
	}

	BFS(0, 0);
	cout << dis[M - 1][N - 1] << "\n";

}
