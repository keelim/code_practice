#include <iostream>
using namespace std;
int go(int sum, int goal)
{
    if (sum > goal)
    {
        return 0;
    } // 안되는 조건

    if (sum == goal)
    {
        return 1;
    } //되는 조건

    int now = 0;
    for (int i = 1; i <= 3; i++)
    {
        now += go(sum + i, goal);
    } //dusthrwhrjs
    return now;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << go(0, n) << '\n';
    }
    return 0;
}