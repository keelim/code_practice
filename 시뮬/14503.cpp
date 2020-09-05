#include <iostream>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int a[55][55];

int main()
{
    int n, m;
    cin >> n >> m;

    int x, y, dir;
    cin >> x >> y >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int cnt = 0;

    while(1){
        if(a[x][y]==0) a[x][y] = 2;

        
    }
}
