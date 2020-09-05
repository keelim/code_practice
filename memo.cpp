#include <iostream>
#include <algorithm>

using namespace std;

int map[21][21];
bool visited[21];

int n;
int ans = 999999999;

void dfs(int index, int cnt)
{
    if (cnt == n / 2)
    {
        int a = 0;
        int b = 0;

        for (int i = 0; i < n; i++)
        { // 다시 순황을 하는 구나
            for (int j = i + 1; j < n; j++)
            {
                if (visited[i] && visited[j])
                {
                    a += map[i][j];
                    a += map[j][i];
                }
                else if (!visited[i] && !visited[j])
                {
                    b += map[i][j];
                    b += map[j][i];
                }
            }
        }
        ans = min(ans, abs(a - b));
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        dfs(i, cnt + 1);
        visited[i] = 0; //조합을 구하는 방법
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}