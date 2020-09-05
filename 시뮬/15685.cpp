#include <iostream>
#include <vector>

using namespace std;

int n, x, y, d, g;
int map[101][101];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> vc;

void makeDragonCurve()
{
    int s = vc.size();
    for (int i = s - 1; i >= 0; i--)
    {
        int dir = (vc[i] + 1) % 4;
        x = x + dx[dir];
        y = y + dy[dir];
        map[x][y] = 1;

        vc.push_back(dir);
    }
}

void countSquare()
{
    int count = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)    
            if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
                count++;
     
    cout << count << "\n";
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> y >> x >> d >> g;

        vc.clear();

        map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = 1;

        vc.push_back(d);
        for (int j = 0; j < g; j++)
            makeDragonCurve();
    }

    countSquare();

    return 0;
}
