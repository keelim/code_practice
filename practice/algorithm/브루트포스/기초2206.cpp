#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct

{
    int y, x;

} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;

int map[1001][1001];

int visited[1001][1001][2]; //마지막 2는 벽 뚫기 여부

int BFS(void)

{

    queue<pair<pair<int, int>, int>> q; //y, x, 벽 뚫기
    q.push(make_pair(make_pair(0, 0), 1)); //시작점, 벽 뚫기 가능
    visited[0][0][1] = 1;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();

        //도착하면

        if (y == N - 1 && x == M - 1)
            return visited[y][x][block]; //시작하는 칸도 포함

        for (int i = 0; i < 4; i++)
        {
            int nx = x + moveDir[i].x;
            int ny = y + moveDir[i].y;
            if(nx<0||ny<0||nx>=M||ny>=N) continue;
            
                //벽이 있고, 벽을 아직 안 뚫었다면
                if (map[ny][nx] == 1 && block)
                {
                    visited[ny][nx][block - 1] = visited[y][x][block] + 1;
                    q.push(make_pair(make_pair(ny, nx), block - 1));
                }

                //벽이 없고 방문하지 않았던 곳이라면
                else if (map[ny][nx] == 0 && visited[ny][nx][block] == 0)
                {
                    visited[ny][nx][block] = visited[y][x][block] + 1;
                    q.push(make_pair(make_pair(ny, nx), block));
                }
        }
    }

    return -1;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            map[i][j] = temp[j] - '0';
    }

    cout << BFS() << "\n";
}