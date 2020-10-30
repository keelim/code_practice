#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 4;
    vector<string> map(n);
    for (int i = 0; i < n; i++)
        cin >> map[i];

    int k;
    cin >> k;
    while (k--)
    {
        int no, dir;
        cin >> no >> dir;
        no -= 1;
        // 각각의 톱니는 동시에 회전해야 하기 때문에
        // 먼저, 각 톱니가 어떤 방향으로 회전해야 하는지 구하자
        vector<int> d(n);
        d[no] = dir;
        // 왼쪽 톱니를 연쇄적으로 구하고
        for (int i = no - 1; i >= 0; i--)
        {
            if (map[i][2] != map[i + 1][6])
                d[i] = -d[i + 1];
            else
                break;
            // 한 톱니가 회전하지 않으면
            // 그 톱니의 왼쪽에 있는 톱니도 회전하지 않는다.
        }

        // 오른쪽 톱니를 연쇄적으로 구하고
        for (int i = no + 1; i < n; i++)
        {
            if (map[i - 1][2] != map[i][6])
                d[i] = -d[i - 1];

            else
                break;
            // 한 톱니가 회전하지 않으면
            // 그 톱니의 오른쪽에 있는 톱니도 회전하지 않는다.
        }

        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0)
                continue;
            if (d[i] == 1)
            {
                // 시계 방향 회전
                char temp = map[i][7];
                for (int j = 7; j >= 1; j--)
                {
                    map[i][j] = map[i][j - 1];
                }
                map[i][0] = temp;
            }
            else if (d[i] == -1)
            {
                // 반시계 방향 회전
                char temp = map[i][0];
                for (int j = 0; j < 7; j++)
                {
                    map[i][j] = map[i][j + 1];
                }
                map[i][7] = temp;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (map[i][0] == '1')
            ans |= (1 << i);
    }
    cout << ans << '\n';
    return 0;
}