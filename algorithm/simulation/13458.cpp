#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, b, c;
    cin >> n;
    vector<int> vc;

    for (int i = 0; i < n; i++)
        cin >> vc[i];

    cin >> b >> c;

    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        vc[i] -= b;
        answer++;
        if (vc[i] <= 0)
            continue;

        if (vc[i] % c > 0)
            answer++;

        answer += vc[i] / c;
    }

    cout << answer << "\n";
}
