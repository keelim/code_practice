#include <iostream>
#include <math.h>
using namespace std;

int n, m, h, answer;
int map[11][30];
bool visited[11][30];

bool ladder()
{
    for(int i=1; i<=n; i++){
        int current = i;
        for(int j=1; j<=h; j++){}
    }
}

void selectLine(int idx, int virusCount)
{ // 조합을 만드는 함수 외워두자

    if (virusCount < 4)
        return;
    if (ladder())
    {
        answer = min(answer, virusCount);
        return;
    }

    for (int i = idx; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (visited[j][i])
                continue;
            if (visited[j - 1][i])
                continue;
            if (visited[j + 1][i])
                continue;

            visited[j][i] = true;
            selectLine(i, virusCount + 1);
            visited[j][i] = false;
        }
    }
}

int main()
{
    // 입력
    answer = 99999999;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        visited[a][b] = true;
    }

    // 풀기
    selectLine(1, 0);

    // 출력

    if (answer == 99999999)
        answer = -1;
    cout << answer << "\n";
}