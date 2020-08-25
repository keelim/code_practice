#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int left = 0;
    int right = 0; // left ~ right 까지
    int sum = a[0];
    int ans = 0;
    while (left <= right && right < n)
    {
        if (sum < s)
        {
            right += 1;
            sum += a[right];
        }
        else if (sum == s)
        {
            ans += 1;
            right += 1;
            sum += a[right];
        }
        else if (sum > s)
        {
            sum -= a[left];
            left++;
            if (left > right && left < n)
            {
                right = left;
                sum = a[left];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}