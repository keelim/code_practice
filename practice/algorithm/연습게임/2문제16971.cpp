#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int calc(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            ans += a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
        }
    }
    return ans;
}
void swap_row(vector<vector<int>> &a, int r1, int r2)
{
    int m = a[0].size();
    for (int j = 0; j < m; j++)
    {
        swap(a[r1][j], a[r2][j]);
    }
}
void swap_col(vector<vector<int>> &a, int c1, int c2)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        swap(a[i][c1], a[i][c2]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = calc(a);
    vector<int> sum_row(n, 0);
    vector<int> sum_col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum_row[i] += a[i][j];
            sum_col[j] += a[i][j];
        }
    }
    int min_row = -1;
    for (int i = 1; i < n - 1; i++)
    {
        sum_row[i] = sum_row[i] * 4;
        sum_row[i] -= 2 * (a[i][0] + a[i][m - 1]);
        if (min_row == -1 || sum_row[min_row] > sum_row[i])
        {
            min_row = i;
        }
    }
    int min_col = -1;
    for (int j = 1; j < m - 1; j++)
    {
        sum_col[j] = sum_col[j] * 4;
        sum_col[j] -= 2 * (a[0][j] + a[n - 1][j]);
        if (min_col == -1 || sum_col[min_col] > sum_col[j])
        {
            min_col = j;
        }
    }
    if (min_row != -1)
    {
        swap_row(a, 0, min_row);
        int temp = calc(a);
        if (ans < temp)
            ans = temp;
        swap_row(a, 0, min_row);
        swap_row(a, n - 1, min_row);
        int temp2 = calc(a);
        if (ans < temp2)
            ans = temp2;
        swap_row(a, n - 1, min_row);
    }
    if (min_col != -1)
    {
        swap_col(a, 0, min_col);
        int temp3 = calc(a);
        if (ans < temp3)
            ans = temp3;
        swap_col(a, 0, min_col);
        swap_col(a, m - 1, min_col);
        int temp4 = calc(a);
        if (ans < temp4)
            ans = temp4;
        swap_col(a, m - 1, min_col);
    }
    cout << ans << '\n';
    return 0;
}
