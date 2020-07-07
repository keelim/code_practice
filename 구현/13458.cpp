#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b, c;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> b >> c;

    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] -= b;
        answer++;
        if (a[i] <= 0)
            continue;

        if (a[i] % c > 0)
            answer++;

        answer += a[i] / c;
    }
    
    cout << answer << "\n";
}
