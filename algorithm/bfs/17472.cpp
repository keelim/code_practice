#include <iostream>
#include <queue>
#include <vector>
#include <cstring> //memset 사용

#define INF 1000
using namespace std;

int n, m, areaNum, answer = INF;
int map[10][10];   // 입력 받을 맵
int label[10][10]; // 각 섬마다 번호를 붙이기 위해 사용한 맵
int dist[7][7];    // 각 섬의 최단거리를 저장하기 위한 배열.
                   // Dist[a][b] = C : a와 b의 최단거리는 c입니다.

bool visited[10][10];  // BFS탐색 시, 방문체크를 위한 배열(섬의 번호 붙일 때 사용)
bool connect[7][7];    // 연결관계 체크를 위한 배열
bool connectIsland[7]; // BFS탐색 시, 방문체크를 위한 배열(연결관계를 통해, 정답을 도출하기 위한 BFS탐색 시 사용)
bool select[7 * 7];    // 조합 추출에서 중복 추출을 막기 위한 배열.

/* Select배열의 크기 : 7 * 7 
   - 섬이 N개 존재하고, 이 섬들을 연결한다고 가정했을 때
     나올 수 있는 간선의 최대 갯수는 N(N-1)/2 개 입니다
*/

vector<pair<int, int>> vc;                    // 입력 시, 모든 섬의 좌표들을 저장하기 위한 벡터
vector<pair<int, int>> areaPos[10 + 1];       // 각 섬에 존재하는 땅의 좌표들을 저장하기 위한 벡터배열
vector<pair<pair<int, int>, int>> bridgeList; // 섬과 섬을 연결하는 다리의 길이와, 그 다리가 어떤 섬을 연결하는지 저장하기 위한 벡터.

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b, int Num)
{
    /* 
       연결된 땅을 탐색하면서 번호를 붙이는 함수.
       (a, b) = 탐색을 시작할 첫 정점의 좌표.
       Num = 탐색할 땅들의 붙일 섬 번호.
    */
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    label[a][b] = Num;
    areaPos[Num].push_back({a, b});
    /* 
       설명에서도 말했듯이, 섬의 번호를 붙이면서 동시에
       각 섬에 존재하는 땅덩어리의 좌표들을 벡터배열에 저장해준다.
       이 벡터배열은, 이 후 섬들간의 최단거리를 구하는데 사용.
    */

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (visited[nx][ny] == false && map[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                label[nx][ny] = Num;
                q.push({nx, ny});
                areaPos[Num].push_back({nx, ny});
            }
        }
    }
}

void makeLabel()
{
    /* 
        섬의 번호를 붙이는 함수
        입력 시 저장해 놓은 Vector를 순차적으로 탐색하면서
        아직 방문하지 않은 좌표들에 대해서는 BFS 탐색 실시.
    */
    int labelNum = 1;
    for (int i = 0; i < vc.size(); i++)
    {
        int x = vc[i].first;
        int y = vc[i].second;

        if (visited[x][y] == false)
            bfs(x, y, labelNum++);
    }
    areaNum = labelNum; // 섬의 최종적인 갯수 = Area_Num - 1
}

void dfs(int x, int y, int dir, int B_Size, int Start, int End)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        return; // 맵의 범위를 벗어나면 return

    if (map[nx][ny] == 0)
        dfs(nx, ny, dir, B_Size + 1, Start, End); // 아직 바다라면 계속 탐색.
    else if (map[nx][ny] == 1)                    // 탐색하려는 정점이 땅이라면
    {
        if (label[nx][ny] == End) // 그 땅이 도착섬이라면 ?
        {
            if (B_Size > 1) // 다리의 길이가 2이상인지 체크
            {
                if (dist[Start][End] > B_Size) // 최소길이로 갱신
                {
                    dist[Start][End] = B_Size;
                    dist[End][Start] = B_Size;
                }
                return;
            }
        }
        else
            return; // 도착점이 아닌 다른 섬이라면 return.
    }
}

int Reverse(int dir)
{
    if (dir == 0)
        return 1;
    else if (dir == 1)
        return 0;
    else if (dir == 2)
        return 3;
    else if (dir == 3)
        return 2;
}

void MakeBridge(int Start, int End)
{
    /* 시작 섬에 존재하는 모든 땅덩어리 들에서 도착 섬까지 탐색해본다.*/
    for (int i = 0; i < areaPos[Start].size(); i++)
    {
        int x = areaPos[Start][i].first;
        int y = areaPos[Start][i].second;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (map[nx][ny] == 0)
                    dfs(x, y, j, 0, Start, End);
            }
        }
    }
}

bool CheckState()
{
    memset(connect, false, sizeof(connect));
    memset(connectIsland, false, sizeof(connectIsland));
    for (int i = 0; i < bridgeList.size(); i++)
    {
        if (select[i] == true)
        {
            int x = bridgeList[i].first.first;
            int y = bridgeList[i].first.second;

            connect[x][y] = true; // 선택한 다리가 연결하는 섬들의 연결관계를 표시
            connect[y][x] = true;
        }
    }

    // 이후 BFS탐색을 통해서 탐색할 수 있는 섬의 갯수를 Count.
    queue<int> Q;
    Q.push(1);
    connectIsland[1] = true;

    int IslandCnt = 1;
    bool Flag = false;
    while (Q.empty() == 0)
    {
        int Cur = Q.front();
        Q.pop();

        if (IslandCnt == areaNum - 1)
        {
            Flag = true;
            break;
        }

        for (int i = 1; i < areaNum; i++)
        {
            if (Cur == i)
                continue;
            if (connect[Cur][i] == true && connectIsland[i] == false)
            {
                connectIsland[i] = true;
                Q.push(i);
                IslandCnt++;
            }
        }
    }
    return Flag;
}

void FindDistance()
{
    /*
    섬들간의 최단거리를 구하기 위한 함수.
    시작점과 끝점을 정한 후, DFS를 통해서 구현.
    */
    for (int i = 1; i < areaNum; i++)
    {
        for (int j = i + 1; j < areaNum; j++)
        {
            MakeBridge(i, j);
            if (dist[i][j] == INF)
                continue;
            bridgeList.push_back(make_pair(make_pair(i, j), dist[i][j]));
            // 다리의 최소거리를 구했으면, BridgeList 벡터에 다리가 연결하는 2개의 섬과, 그 거리 총 3개의 데이터를 저장.
        }
    }
}

void DistDFS(int Idx, int Cnt, int Sum)
{
    /* 조합 구현을 통해서 정답을 도출하기 위한 함수.*/
    if (Cnt >= 1) // 1개이상만 뽑았으면 무조건 확인해본다.
    {
        if (CheckState() == true)
        {
            if (answer > Sum)
                answer = Sum;
        }
    }

    for (int i = Idx; i < bridgeList.size(); i++)
    {
        if (select[i] == true)
            continue;
        select[i] = true;
        DistDFS(i, Cnt + 1, Sum + bridgeList[i].second);
        select[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            dist[i][j] = INF;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                vc.push_back({i, j}); // 입력과 동시에, 섬의 좌표들은 모두 저장.
        }
    }

    //input

    makeLabel();      // 섬의 번호 붙이기
    FindDistance();   // 섬 끼리 최단거리 구하기
    DistDFS(0, 0, 0); // 정답 도출하기

    if (answer == INF)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
}
