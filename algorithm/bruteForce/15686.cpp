#include <iostream>
#include <vector>
#include <cmath>

#define MAX 50
using namespace std;

int n, m, checkNum, answer;
int map[MAX][MAX];
bool selected[13];

vector<pair<int, int>> house, chicken, v;

int calcDistance()
{
    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int x = house[i].first;
        int y = house[i].second;
        int d = 99999999;

        for (int j = 0; j < v.size(); j++)
        {
            int xx = v[j].first;
            int yy = v[j].second;
            int dist = abs(xx - x) + abs(yy - y);

            d = min(d, dist);
        }
        sum += d;
    }
    return sum;
}

void selectChicken(int index, int virusCount)
{
    if (virusCount == m)
    {
        answer = min(answer, calcDistance());
        return;
    }

    for (int i = index; i < checkNum; i++)
    {
        if (selected[i] == true)
            continue;
            
        selected[i] = true;
        v.push_back(chicken[i]);
        selectChicken(i, virusCount + 1);
        selected[i] = false;
        v.pop_back();
    }
}

int main(void)
{

    answer = 99999999;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                house.push_back(make_pair(i, j));
            if (map[i][j] == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    checkNum = chicken.size();

    selectChicken(0, 0);

    cout << answer << "\n";
}
