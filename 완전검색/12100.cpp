#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, answer;
int map[20][20];
int cmap[20][20];
int selected[5];
bool visited[20][20];

void copyMap()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cmap[i][j] = map[i][j];
}

void moveLeft()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = j + 1;
                while (k <= n - 1)
                {
                    if (cmap[i][k] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true)
                {
                    cmap[i][j] = cmap[i][k];
                    cmap[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (cmap[i][j] == cmap[i][j + 1])
            {
                cmap[i][j] = cmap[i][j] * 2;
                cmap[i][j + 1] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = j + 1;
                while (k <= n - 1)
                {
                    if (cmap[i][k] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }
                if (check == true)
                {
                    cmap[i][j] = cmap[i][k];
                    cmap[i][k] = 0;
                }
            }
        }
    }
}

void moveRight()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (cmap[i][k] != 0)
                    {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true)
                {
                    cmap[i][j] = cmap[i][k];
                    cmap[i][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (cmap[i][j] == cmap[i][j - 1])
            {
                cmap[i][j] = cmap[i][j] * 2;
                cmap[i][j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            bool Check = false;
            if (cmap[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (cmap[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    cmap[i][j] = cmap[i][k];
                    cmap[i][k] = 0;
                }
            }
        }
    }
}

void moveUp()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = i + 1;
                while (k <= n - 1)
                {
                    if (cmap[k][j] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }

                if (check == true)
                {
                    cmap[i][j] = cmap[k][j];
                    cmap[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cmap[i][j] == cmap[i + 1][j])
            {
                cmap[i][j] = cmap[i][j] * 2;
                cmap[i + 1][j] = 0;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = i + 1;
                while (k <= n - 1)
                {
                    if (cmap[k][j] != 0)
                    {
                        check = true;
                        break;
                    }
                    k++;
                }

                if (check == true)
                {
                    cmap[i][j] = cmap[k][j];
                    cmap[k][j] = 0;
                }
            }
        }
    }
}

void moveDown()
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            bool check = false;
            if (cmap[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (cmap[k][j] != 0)
                    {
                        check = true;
                        break;
                    }
                    k--;
                }
                if (check == true)
                {
                    cmap[i][j] = cmap[k][j];
                    cmap[k][j] = 0;
                }
            }
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (cmap[i - 1][j] == cmap[i][j])
            {
                cmap[i][j] = cmap[i][j] * 2;
                cmap[i - 1][j] = 0;
            }
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            bool Check = false;
            if (cmap[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (cmap[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    cmap[i][j] = cmap[k][j];
                    cmap[k][j] = 0;
                }
            }
        }
    }
}

int findMax()
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cmap[i][j] > max)
                max = cmap[i][j];
        }
    }
    return max;
}

void game()
{
    for (int i = 0; i < 5; i++)
    {
        int dir = selected[i];
        if (dir == 0)
            moveRight();
        else if (dir == 1)
            moveLeft();
        else if (dir == 2)
            moveDown();
        else if (dir == 3)
            moveUp();
    }

    answer = max(answer, findMax());
}

void selectDirection(int idx, int cnt)
{
    if (cnt == 5) //재귀
    {
        copyMap();
        game();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        selected[cnt] = i;
        selectDirection(i, cnt + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    selectDirection(0, 0);
    cout << answer << "\n";
}