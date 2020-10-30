#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> a[i];
    }
    if (l % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = 'O';
            }
        }
    }
    else
    {
        for (int t = 1; t <= l - 1; t += 2)
        {
            vector<string> temp(a);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    bool bomb = false;
                    if (a[i][j] == 'O')
                    {
                        bomb = true;
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (0 <= x && x < n && 0 <= y && y < m)
                        {
                            if (a[x][y] == 'O')
                            {
                                bomb = true;
                            }
                        }
                    }
                    if (bomb)
                    {
                        temp[i][j] = '.';
                    }
                    else
                    {
                        temp[i][j] = 'O';
                    }
                }
            }
            a = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\n';
    }
    return 0;
}
