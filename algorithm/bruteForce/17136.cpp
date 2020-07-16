#include <iostream>
#include <algorithm>
using namespace std;

int inf = 987654321;
int map[10][10];
int cnt, result;
int paper[6] = {0, 5, 5, 5, 5, 5};

void func(int y, int x)
{
    // 해당 줄은 다 확인했으므로 다음 줄 확인
    if (x == 10)
    {
        func(y + 1, 0);
        return;
    }

    // 마지막 줄까지 다 확인했으므로 현재 색종이 개수 확인
    if (y == 10)
    {
        result = min(result, cnt);
        return;
    }

    // 덮을 필요 없으므로 다음 칸 확인
    if (map[y][x] == 0)
    {
        func(y, x + 1);
        return;
    }

    // 모든 경우의 수 다 확인
    for (int len = 5; len >= 1; len--)
    {
        // 현재 len 크기 색종이가 없거나 덮었을 때 범위를 벗어날 경우
        if (paper[len] == 0 || y + len > 10 || x + len > 10) continue;

        bool flag = true;
        // len 길이만한 정사각형이 존재하는지 확인
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                if (map[y + j][x + k] == 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag == false)
                break;
        }

        // 존재하지 않으면 확인할 필요 없음
        if (flag == false)
            continue;

        // 덮었다고 치고
        for (int j = 0; j < len; j++)
            for (int k = 0; k < len; k++)
                map[y + j][x + k] = 0;

        paper[len]--;
        cnt++;

        // 다음 칸 확인
        func(y, x + len);

        // 덮었던 색종이를 치운다
        for (int j = 0; j < len; j++)
            for (int k = 0; k < len; k++)
                map[y + j][x + k] = 1;

        paper[len]++;
        cnt--;
    }
}

int main(void)
{

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];

    result = inf;
    func(0, 0); //결과 확인

    if (result == inf)
        cout << -1 << "\n";
    else
        cout << result << "\n";
}