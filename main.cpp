#include <iostream>
#include <queue>

using namespace std;

int adj[101][101];
int visited[101][101];
queue<pair<int, int>> q;
int num;

void bfs(int x, int y)
{

    visited[x][y] = 1;
    q.push(make_pair(x, y));

    while (!q.empty())
    {

        for (int i = 0; i < num; i++)
            if (adj[q.front().second][i] && !visited[x][i])
            {
                visited[x][i] = 1;
                q.push(make_pair(q.front().second, i));
            }
        q.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> adj[i][j];
    //input

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            if (adj[i][j])
                bfs(i, j);
    //solution

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }
    //output
}