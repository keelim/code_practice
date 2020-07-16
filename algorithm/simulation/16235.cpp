#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 11
using namespace std;

int n, m, k;
int energy[MAX][MAX];
int insertEnergy[MAX][MAX];

vector<int> map[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springAndSummer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].size() == 0)
                continue;

            int dieTreeEnergy = 0;
            vector<int> temp;

            sort(map[i][j].begin(), map[i][j].end());
            for (int k = 0; k < map[i][j].size(); k++)
            {
                int age = map[i][j][k];

                if (energy[i][j] >= age)
                {
                    energy[i][j] = energy[i][j] - age;
                    temp.push_back(age + 1);
                }
                else
                {
                    dieTreeEnergy = dieTreeEnergy + (age / 2);
                }
            }

            map[i][j].clear();
            for (int k = 0; k < temp.size(); k++)
            {
                map[i][j].push_back(temp[k]);
            }
            energy[i][j] = energy[i][j] + dieTreeEnergy;
        }
    }
}

void fall()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].size() == 0)
                continue;

            for (int k = 0; k < map[i][j].size(); k++)
            {
                int age = map[i][j][k];

                if (age % 5 == 0)
                {
                    for (int a = 0; a < 8; a++)
                    {
                        int nx = i + dx[a];
                        int ny = j + dy[a];

                        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
                        {
                            map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            energy[i][j] = energy[i][j] + insertEnergy[i][j];
        }
    }
}

int main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> insertEnergy[i][j];
            energy[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b].push_back(c);
    }

    for (int i = 0; i < k; i++)
    {
        springAndSummer();
        fall();
        winter();
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            answer += map[i][j].size();
        }
    }

    cout << answer << "\n";
}