#include <iostream>
#include <algorithm>
using namespace std;

int d[16];
int t[16];
int p[16];
int n, answer;

//dp의 경우
int dp(int day)
{
    if (day == n + 1)
        return 0;
    //날짜가 n+1보다 크다면 -값을 크게 준다.
    if (day > n + 1)
        return -987654321;
    //메모이제이션
    if (d[day] > 0)
        return d[day];
    //점화식 상담을 안한다 혹은 상담을 한다. 둘 중 하나를 고른다.
    return d[day] = max(dp(day + 1), dp(day + t[day]) + p[day]); //재귀가 들어감
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    // 입력을 하는 부분
    cout << dp(1) << "\n";

    return 0;
}
