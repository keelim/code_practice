#include <iostream>
using namespace std; //3~4 중으로 넘어가면 재귀가 효과적이다.

int answer;
int n;
void solve(int sum)
{
    //1, 2, 3 중에 더하는 거라서 n을 넘어갈 수도 있음. 그 경우를 처리해줘야 한다.
    if (sum > n)
        return;
    //n과 일치하면 경우의 수 1개 증가
    if (sum == n)
        answer++;
    //sum이 아직 n에 도달하지 않으면 1, 2, 3을 한 번 더 더해본다.
    solve(sum + 1);
    solve(sum + 2);
    solve(sum + 3);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        answer = 0; //test case가 여러 개므로 재귀 들어가기 전 0으로 초기화한다.
        solve(0);
        cout << answer << endl;
    }

    return 0;
}