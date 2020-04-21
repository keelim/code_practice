#include <iostream>
using namespace std;

int solution(int n)
{
    int sum = n;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int sum = solution(i);
        if (sum == N)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}