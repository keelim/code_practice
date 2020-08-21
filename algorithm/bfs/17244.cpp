#include <iostream>
#include <queue>
using namespace std;
int n, m;

int map[51][51];
bool visited[51][51];

int main()
{
    cin >> m >> n; // m - x , n - y
    for (int i = 0; i < n; i++)
    {
        char cs[n];
        cin >> cs;
        for (int j = 0; i < m; i++)
        {
            if (cs[j] == '#')
                map[i][j] = 0;
            else if (cs[j] == '.')
                map[i][j] = 1;
            else if (cs[j] == 'S')
                map[i][j] = 7;
            else if (cs[j] == 'X')
                map[i][j] = 8;
            else if (cs[j] == 'E')
                map[i][j] = 9;
        }
    } //input

    


    return 0;
}