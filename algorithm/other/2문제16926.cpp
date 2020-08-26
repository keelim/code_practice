#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[300][300];
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> groups;
    int groupn = min(n, m) / 2;
    for (int k = 0; k < groupn; k++)
    {
        vector<int> group;
        for (int j = k; j < m - k; j++)
        {
            group.push_back(a[k][j]);
        }
        for (int i = k + 1; i < n - k - 1; i++)
        {
            group.push_back(a[i][m - k - 1]);
        }
        for (int j = m - k - 1; j > k; j--)
        {
            group.push_back(a[n - k - 1][j]);
        }
        for (int i = n - k - 1; i > k; i--)
        {
            group.push_back(a[i][k]);
        }
        groups.push_back(group);
    }
    for (int k = 0; k < groupn; k++)
    {
        vector<int> &group = groups[k];
        int len = group.size();
        int index = r % len;
        for (int j = k; j < m - k; j++, index = (index + 1) % len)
        {
            a[k][j] = group[index];
        }
        for (int i = k + 1; i < n - k - 1; i++, index = (index + 1) % len)
        {
            a[i][m - k - 1] = group[index];
        }
        for (int j = m - k - 1; j > k; j--, index = (index + 1) % len)
        {
            a[n - k - 1][j] = group[index];
        }
        for (int i = n - k - 1; i > k; i--, index = (index + 1) % len)
        {
            a[i][k] = group[index];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
