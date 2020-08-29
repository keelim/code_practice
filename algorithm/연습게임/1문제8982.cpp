#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n -= 2;
    n /= 2;
    vector<int> bottom(n, -1);
    vector<bool> hole(n, false);
    vector<int> top(n, 0);
    vector<int> width(n, 0);
    map<int, int> dict;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bottom[i] = y1;
        width[i] = (x2 - x1);
        dict[x2] = i;
    }
    cin >> x >> y;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int index = dict[x2];
        hole[index] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (hole[i] == false)
            continue;
        int surface = bottom[i];
        for (int j = i; j >= 0; j--)
        {
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
        surface = bottom[i];
        for (int j = i + 1; j < n; j++)
        {
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (bottom[i] > top[i])
        {
            ans += (long long)(bottom[i] - top[i]) * width[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
