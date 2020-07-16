#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;


typedef struct
{
    int y, x;
} dir;

dir moveDir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //E S W N

int n, k, l;
bool map[100][100];
bool visited[100][100];

int main(void)
{
    cin >> n;
    cin >> k;
    for (int k = 0; k < k; k++)
    {
        int y, x;
        cin >> y >> x;

        map[y - 1][x - 1] = true;
    }

    cin >> l;
    deque<pair<int, char>> dq;

    for (int l = 0; l < l; l++)
    {
        int X;
        char C;
        cin >> X >> C;

        dq.push_back({X, C});
    }

    int sec = 0;
    int idx = 0; //초기 오른쪽
    
    deque<pair<int, int>> snake;
    snake.push_back({0, 0}); //초기 위치
    visited[0][0] = true;

    while (1)
    {
        sec++;
        pair<int, int> before = snake.back();
        pair<int, int> cur = {before.first + moveDir[idx].y, before.second + moveDir[idx].x};
        //뱀의 머리가 몸에 부딪히거나, 범위를 벗어날 경우
        if (visited[cur.first][cur.second] || !(0 <= cur.first && cur.first < n && 0 <= cur.second && cur.second < n))
        {
            cout << sec << "\n";
            break;
        }

        visited[cur.first][cur.second] = true;
        snake.push_back(cur);
        //사과가 있는 위치면 꼬리 그대로
        if (map[cur.first][cur.second])
            map[cur.first][cur.second] = false;
        //사과 없으면 꼬리가 있던 칸을 지운다
        else
        {
            pair<int, int> tail = snake.front();
            visited[tail.first][tail.second] = false;
            snake.pop_front();
        }

        //마지막에 방향 전환
        if (dq.size() && dq.front().first == sec)
        {
            if (dq.front().second == 'L')
                idx = (idx + 3) % 4;
            else
                idx = (idx + 1) % 4;
            dq.pop_front();
        }
    }

}