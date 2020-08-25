#include <iostream>
using namespace std;
bool a[201][201];
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (a[i][j] || a[j][k] || a[k][i])
                    continue;
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}