#include <iostream>

#define endl "\n"
#define MAX 10 + 1
using namespace std;

int n, Answer = 987654321;
int map[MAX][MAX];
bool visited[MAX];
int start;

void dfs(int node, int cost, int cnt)
{
    if (cnt == n - 1)
    {
        if (map[node][start])
        {
            Answer = min(Answer, cost + map[node][start]);
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (map[node][i] && !visited[i])
        {
            visited[i] = true;
            dfs(i, cost + map[node][i], cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        start = i;
        visited[i] = 1;
        dfs(i, 0, 0);
        visited[i] = 0;
    }
    cout << Answer << endl;

    return 0;
}
