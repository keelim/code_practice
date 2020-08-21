#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define endl "\n"
#define MAX 50
using namespace std;

int n, m, K, Answer;
int MAP[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<pair<int, int>> V;

void Initialize()
{
    Answer = 0;
    V.clear();
}

void input()
{
    cin >> m >> n >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        MAP[y][x] = 1;
        V.push_back(make_pair(y, x));
    }

    /*for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }*/
}

void BFS(int a, int b)
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (visited[nx][ny] == false && MAP[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    Answer++;
}

int main(void)
{

    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        input();
        for (int i = 0; i < V.size(); i++)
        {
            int x = V[i].first;
            int y = V[i].second;

            if (visited[x][y] == false)
            {
                //cout << "(x,y) = (" << x << "," << y << ")" << endl;
                BFS(x, y);
            }
        }

        cout << Answer << endl;
    }

    return 0;
}
