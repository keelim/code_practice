#include <iostream>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;
int distance[101];
int next[101];
int main()
{
    int n,
        m;
    cin >> n >> m;
    for (int i = 1; i <= 100; i++)
    {
        next[i] = i;
        distance[i] = -1;
    }
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    distance[1] = 0;
    queue<int> q;

    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int y = x + i;
            if (y > 100)
                continue;

            y = next[y];
            if (distance[y] == -1)
            {
                distance[y] = distance[x] + 1;

                q.push(y);
            }
        }
    }
    cout << distance[100] << '\n';
    return 0;
}