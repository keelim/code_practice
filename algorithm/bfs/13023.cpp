// 전부 연결이 되었느냐를 보이고 는 것 과 같다.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> map[2001];
bool visited[2001];
int m, n;

void bfs(int a, int b){
    queue<pair<int, int>> q;
    
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int first, second;

        cin >> first >> second;

        map[first].push_back(second);
        map[second].push_back(first);
    }

    bfs(0, 0);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            ans = 0;
        }
    }
    cout << ans;
}