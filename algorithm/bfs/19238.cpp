#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 25
using namespace std;

/* 손님을 관리하기 위한 구조체 */
/* 알아야할 정보 = [ 손님의 좌표 , 손님의 목적지 좌표 ] */
struct Customer
{
    int x;
    int y;
    int dx;
    int dy;
};

/* 조건에 맞는 손님을 찾기 위한 정보를 관리하는 구조체 */
/* 알아야할 정보 = [ x좌표 , y좌표 , 거리 , 손님의 번호 ] */
struct Info
{
    int x;
    int y;
    int dist;
    int num;
};

int n, m, fuel;
int taxiX, taxiY;
int map[MAX][MAX];
bool visited[MAX][MAX];
Customer customer[MAX * MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool infoCmp(Info a, Info b)
{
    /* 조건에 맞는 손님을 찾기 위해서 Vector를 정렬하기 위한 기준 설정. */
    if (a.dist <= b.dist)
    {
        if (a.dist == b.dist)
        {
            if (a.x <= b.x)
            {
                if (a.x == b.x)
                {
                    if (a.y < b.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool bfs(int a, int b, int c, int d, int Num)
{
    /* 손님을 최단 거리로 목적지까지 이동시키기 위한 BFS 탐색 함수. */
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(a, b), make_pair(0, fuel)));
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second.first;
        int spareFuel = q.front().second.second;
        q.pop();

        /* 목적지에 도달한다면 ? */
        /* 연료의 양을 문제의 조건에 맞게 재설정. */
        /* 택시의 위치를, 현재 이동시킨 손님의 목적지 위치로 재설정. */
        if (x == c && y == d)
        {
            fuel = fuel - dist;
            fuel = fuel + (dist * 2);
            taxiX = x;
            taxiY = y;
            return true;
        }
        /* 더 이상 연료가 없다면 ? = 손님을 더 이상 이동시킬 수 없다. */
        if (spareFuel == 0)
            return false;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (map[nx][ny] != -1 && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(dist + 1, spareFuel - 1)));
            }
        }
    }
    return false;
}

int findShortestCustomer()
{
    /* 현재 택시 위치에서 가장 가까운 손님을 찾기 위한 BFS함수. */
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(taxiX, taxiY), make_pair(0, fuel)));
    visited[taxiX][taxiY] = true;
    vector<Info> vc;
    /* 위의 벡터가 "현재 연료의 양으로 찾아갈 수 있는 모든 손님에 대한 정보"를 저장. */
    while (q.empty() == 0)
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second.first;
        int spareFuel = q.front().second.second;
        q.pop();

        /* 맵이 1 이상이라는 것은 해당 좌표에 손님이 있음을 의미. */
        /* 따라서, 해당 좌표에 있는 손님에 대한 정보를 Vector에 저장. */
        if (map[x][y] >= 1)
            vc.push_back({x, y, dist, map[x][y]});
        if (spareFuel == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (map[nx][ny] != -1 && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(dist + 1, spareFuel - 1)));
            }
        }
    }

    /* Vector의 Size = 0 이라는 것은 찾아갈 수 있는 손님이 없음을 의미. */
    if (vc.size() == 0)
        return -1;

    /* 그게 아니라면, 우리가 찾는 딱 한명의 손님을 찾기 위해서 Vector를 정렬. */
    /* 해당 손님은 이제 더 이상 해당 좌표에 없으므로 맵에서 값 변경. */
    /* 현재 택시 위치에서 해당 손님까지 가는데 든 연료만큼 연료의 양 또한 변경. */
    sort(vc.begin(), vc.end(), infoCmp);
    map[vc[0].x][vc[0].y] = 0;
    fuel = fuel - vc[0].dist;
    return vc[0].num;
}

int main()
{

    cin >> n >> m >> fuel;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                map[i][j] = -1;
            // 맵에서 벽으로 표시되는 1을 -1로 변경.
        }
    }
    cin >> taxiX >> taxiY;
    taxiX--;
    taxiY--;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        customer[i] = {a, b, c, d};
        map[a][b] = i;
        // 손님이 있는 위치를 각 손님의 번호로 변경
    }

    /* 아무리 많아도 손님의 수 만큼만 움직이면 된다. */
    /* 따라서, 0 ~ M번까지만 반복. */
    for (int i = 0; i < m; i++)
    {
        int num = findShortestCustomer();
        if (num == -1)
        {
            cout << -1 << "\n";
            return 0;
        }

        bool move = bfs(customer[num].x, customer[num].y, customer[num].dx, customer[num].dy, num);
        if (move == false)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << fuel << "\n";
}
