#include <iostream>
#include <queue>
using namespace std;

int n, m;       // n: 전체 사람의 수, m:부모 자식들 간의 관계 개수
int num1, num2; // 촌수 계산해야하는 두사람 번호
int x, y;       //부머 자식간의 관계
int depth[101];
int map[101][101];
bool visit[101];
queue<int> q;
void bfs(int i)
{
    visit[i] = true;
    q.push(i);
    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (map[temp][j] == 1 && !visit[j])
            {
                visit[j] = true;
                depth[j] = depth[temp] + 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    cin >> n >> num1 >> num2 >> m; //전체 사람의 

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    bfs(num1);
    if (depth[num2] != 0)
        cout << depth[num2] << endl;
    else
        cout << "-1" << endl;
}