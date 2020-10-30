#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int a[51][51];
int c[51][51];
int n, l, r;

bool bfs(int l, int r) // vector을 넣을 때는 이렇게
{
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] == false)
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                c[i][j] = true;
                stack<pair<int, int>> s;
                s.push(make_pair(i, j));
                int sum = a[i][j];
                while (!q.empty())
                {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n)
                        {
                            if (c[nx][ny])
                                continue;
                            int diff = a[nx][ny] - a[x][y];
                            if (diff < 0)
                                diff = -diff;
                            if (l <= diff && diff <= r)
                            {
                                q.push(make_pair(nx, ny));
                                s.push(make_pair(nx, ny));
                                c[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size();
                while (!s.empty())
                {
                    int x, y;
                    tie(x, y) = s.top();
                    s.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}
int main()
{
    
    cin >> n >> l >> r;

    memset(c, 0, sizeof(c));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    while (1)
    {
        if (bfs(l, r))
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}