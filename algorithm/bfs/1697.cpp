#include <iostream>
<<<<<<< HEAD
using namespace std;

int n,k;
int main(){
    cin>>n>>k;


=======
#include <queue>
using namespace std;
#define MAX_VALUE 100001 //인덱스 100000까지 :: +1까지 넣음
bool visited[MAX_VALUE];
int N, M; //N    수빈이위치, M 동생위치

int bfs(int nx, int m)
{
    int time = 0; //몇초만에 찾았는지 ?
    queue<int> q;
    q.push(nx);

    while (!q.empty())
    {
        nx = q.front();
        q.pop();
        if (nx == m) return time;
        if (nx > 0 && visited[nx - 1] == 0)
        {
            q.push(nx - 1);
            visited[nx - 1] = 1;
        }
        if (nx < 100000 && visited[nx + 1] == 0)
        {
            q.push(nx + 1);
            visited[nx + 1] = 1;
        }
        if (nx * 2 <= 100000 && visited[nx * 2] == 0)
        {
            q.push(nx * 2);
            visited[nx * 2] = 1;
        }
        time++;
    }
}

int main()
{
    cin >> N >> M;
    cout << bfs(N, M);
    return 0;
>>>>>>> e782372d2c0c4e87c143f9305c7904f06b0a1f99
}