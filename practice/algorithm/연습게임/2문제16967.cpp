#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<int>> a(h + x, vector<int>(w + y));
    for (int i = 0; i < h + x; i++)
    {
        for (int j = 0; j < w + y; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            a[i + x][j + y] -= a[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
