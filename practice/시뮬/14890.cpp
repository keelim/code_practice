#include <iostream>
#include <vector>
using namespace std;
bool go(vector<int> &a, int l)
{
    // 한 줄 검사
    int n = a.size();
    vector<bool> visited(n, false);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
            continue;

        // 인접한 칸의 높이가 다르면, 경사로를 놓아야 한다.
        int diff = a[i] - a[i - 1];
        if (diff < 0) diff = -diff;
        if (diff != 1) return false;

        // 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.

        if (a[i - 1] < a[i])
        {
            for (int j = 1; j <= l; j++)
            {
                if (i - j < 0) return false;// 경사로를 놓다가 범위를 벗어나는 경우
            
                if (a[i - 1] != a[i - j]) return false; // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                
                if (visited[i - j]) return false; // 경사로를 놓은 곳에 또 경사로를 놓는 경우
                visited[i - j] = true;
            }
        }
        else
        {
            // a[i-1] > a[i]
            for (int j = 0; j < l; j++)
            {
                if (i + j >= n) return false;
                
                    // 경사로를 놓다가 범위를 벗어나는 경우
                if (a[i] != a[i + j]) return false;
                
                    // 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    
                if (visited[i + j]) return false;
                
                    // 경사로를 놓은 곳에 또 경사로를 놓는 경우
                
                visited[i + j] = true;
            }
        }
    }
    return true;
}

int main()
{
    int n, l;
    cin >> n >> l;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j]; //input

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // 행 검사
        vector<int> test;
        for (int j = 0; j < n; j++)
        {
            test.push_back(map[i][j]);
        }
        if (go(test, l))
            ans += 1;
    }
    for (int j = 0; j < n; j++)
    {
        // 열 검사
        vector<int> test;
        for (int i = 0; i < n; i++)
        {
            test.push_back(map[i][j]);
        }
        if (go(test, l))
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}