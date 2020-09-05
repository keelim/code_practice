#include <iostream>
#include <cstring>

using namespace std;

int map[100][100];
bool apple[100][100];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        apple[x - 1][y - 1] = true;
    } // input

    memset(map, -1, sizeof(map));
    int x = 0, y = 0, dir = 0, len = 1;
    map[x][y] = 0;

    cin >> m;
    int now = 0;

    for (int k = 0; k <= m; k++)
    {
        int t = n * n + 1;
        char ch = 'L';
        if (k < m)
            cin >> t >> ch;

        while (now < t)
        {
            now += 1;
            x += dx[dir];
            y += dy[dir];

            if (x < 0 || x >= n || y < 0 || y >= n)
            {
                cout << now << '\n';
                return 0;
            }

            if (map[x][y] != -1 && now - map[x][y] <= len)
            {
                cout << now << '\n';
                return 0;
            }

            if (apple[x][y])
            {
                apple[x][y] = false;
                len += 1;
            }

            map[x][y] = now;
        }

        if (ch == 'L') dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
        
    }
    return 0;
}