#include <iostream>
#include <algorithm>

#define MAX 100
using namespace std;

int n, l;
int map[MAX][MAX];
int cmap[MAX][MAX];

bool canMakeRoad(int a[][MAX], int x, int y)
{
    int standard = a[x][y + 1];
    for (int j = y + 1; j < y + 1 + l; j++)
    {
        if (a[x][j] != standard)
            return false;
    }
    return true;
}

int makeRoad(int A[][MAX])
{
    int totalRoad = 0;
    for (int i = 0; i < n; i++)
    {
        bool canRoad = true;
        int beforeRoad = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (A[i][j] == A[i][j + 1])
                beforeRoad++;
            // 1번 Case
            else if (A[i][j] == A[i][j + 1] + 1) // 2번 Case 앞에것이 더 높을 때
            {
                if (canMakeRoad(A, i, j) == true)
                {
                    j = j + l - 1;
                    beforeRoad = 0;
                }
                else
                {
                    canRoad = false;
                    break;
                }
            }
            else if (A[i][j] + 1 == A[i][j + 1]) // 3번 Case 뒤에것이 더 높을 때
            {
                if (beforeRoad >= l)
                {
                    beforeRoad = 1;
                }
                else
                {
                    canRoad = false;
                    break;
                }
            }
            else if (abs(A[i][j] - A[i][j + 1]) >= 2)
            {
                canRoad = false;
                break;
            }
        }

        if (canRoad == true)
        {
            totalRoad++;
        }
    }
    return totalRoad;
}

int main()
{

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            cmap[j][i] = map[i][j];
        }
    } //input

    int a = makeRoad(map);
    int b = makeRoad(cmap);

    cout << a + b << "\n";
}
