#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define endl "\n"
#define MAX 50 + 5
using namespace std;

int n, m, t, sum, total, answer, avre;
int circle[MAX][MAX];   // 현재 원판을 저장.
int ccircle[MAX][MAX];  // 원판 회전 시, 임시 저장공간.
bool visited[MAX][MAX]; // BFS탐색 시, 방문 체크를 위한 Visit 배열.
vector<pair<pair<int, int>, int>> cmd;

void copyMap(int a[][MAX], int b[][MAX])
{
    /* 맵 복사 함수 */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void turningCircle(int index, int direction, int k)
{
    /* 원판을 회전시키는 함수 
    1. 원판의 상태를 임시 원판에 복사해준다.
    2. 원본의 값들을 이용해서 임시 원판의 값들을 바꿔준다.
    3. 임시 원판을 다시 원본에 복사해준다.
    */
    copyMap(ccircle, circle);
    if (direction == 0)
    {
        for (int i = 0; i < m; i++)
        {
            int value = circle[index][i];
            int position = (i + k) % m;
            ccircle[index][position] = value;
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            int value = circle[index][i];
            int temp = k % m;
            int position = i - temp;
            if (position < 0)
                position += m;
            ccircle[index][position] = value;
        }
    }
    copyMap(circle, ccircle);
}

bool bfs(int a, int b)
{
    /* 인접한 값이 있는지 없는지 탐색하는 BFS 함수. */
    queue<pair<int, int>> q;   // BFS에서 사용할 Queue
    vector<pair<int, int>> vc; // 인접한 값들의 위치를 저장할 Vector
    q.push(make_pair(a, b));
    vc.push_back(make_pair(a, b)); // 현재 값은 무조건 넣어주고 시작. (초기사이즈 = 1)
    visited[a][b] = true;

    while (!q.empty())
    {
        int cnum = q.front().first;
        int index = q.front().second;
        q.pop();

        int lindex = index - 1; // 같은 원판의 왼쪽 값
        int rindex = index + 1; // 같은 원판의 오른쪽 값
        int lcircle = cnum - 1; // 왼쪽 원판의 값
        int rcircle = cnum + 1; // 오른쪽 원판의 값

        if (lindex < 0)
            lindex = m - 1;
        if (rindex >= m)
            rindex = rindex % m;

        if (circle[cnum][index] == circle[cnum][lindex])
        {
            if (visited[cnum][lindex] == false)
            {
                visited[cnum][lindex] = true;
                q.push(make_pair(cnum, lindex));
                vc.push_back(make_pair(cnum, lindex));
            }
        }
        if (circle[cnum][index] == circle[cnum][rindex])
        {
            if (visited[cnum][rindex] == false)
            {
                visited[cnum][rindex] = true;
                q.push(make_pair(cnum, rindex));
                vc.push_back(make_pair(cnum, rindex));
            }
        }
        if (lcircle > 0)
        {
            if (circle[cnum][index] == circle[lcircle][index])
            {
                if (visited[lcircle][index] == false)
                {
                    visited[lcircle][index] = true;
                    q.push(make_pair(lcircle, index));
                    vc.push_back(make_pair(lcircle, index));
                }
            }
        }
        if (rcircle <= n)
        {
            if (circle[cnum][index] == circle[rcircle][index])
            {
                if (visited[rcircle][index] == false)
                {
                    visited[rcircle][index] = true;
                    q.push(make_pair(rcircle, index));
                    vc.push_back(make_pair(rcircle, index));
                }
            }
        }
    }

    if (vc.size() == 1) // 크기가 1이다. = 인접한 값들 중 똑같은 값을 가진 놈이 없다.
    {
        return false;
    }
    else // 그게 아니면 인접한 값들 중 똑같은 값을 가진 놈이 있다.
    {
        for (int i = 0; i < vc.size(); i++)
        {
            int x = vc[i].first;
            int y = vc[i].second;
            circle[x][y] = 0;
        }
        return true;
    }
}

bool checkAdjacency()
{
    /* 인접한 곳에 같은 값이 있는지 체크하는 함수 */
    memset(visited, false, sizeof(visited));
    bool flag = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* 모든 좌표를 돌면서,
            1. 아직 방문 하지 않은 좌표이고
            2. 0이 아닌 좌표들에 대해서 탐색 시작. 
            */
            if (visited[i][j] == false && circle[i][j] != 0)
            {
                bool T = bfs(i, j);
                if (T == true)
                    flag = true;
            }
        }
    }

    return flag;
}

void changeValue(double average)
{
    /* 인접한 값이 없을 경우, 나머지 값들을 평균 값에 따라 ++ , -- 해주는 함수 */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (circle[i][j] == 0)
                continue;

            if ((double)(circle[i][j]) > average)
                circle[i][j]--;

            else if ((double)(circle[i][j]) < average)
                circle[i][j]++;
        }
    }
}

pair<int, int> calculate()
{
    pair<int, int> r;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r.first = r.first + circle[i][j];
            if (circle[i][j] != 0)
                r.second++;
        }
    }
    return r;
}

int main()
{

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> circle[i][j];
        }
    }
    total = n * m;

    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cmd.push_back(make_pair(make_pair(a, b), c));
    }

    for (int i = 0; i < t; i++)
    {
        int num = cmd[i].first.first;
        int dir = cmd[i].first.second;
        int k = cmd[i].second;

        for (int j = num; j <= n; j = j + num)
            turningCircle(j, dir, k);

        bool check = checkAdjacency();
        if (check == false)
        {
            pair<int, int> temp = calculate();
            temp = calculate();
            double Average = (double)(temp.first) / (double)(temp.second);
            changeValue(Average);
        }
    }

    answer = calculate().first;

    cout << answer << endl;
}
