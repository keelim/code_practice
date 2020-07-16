#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 101
using namespace std;

int r, c, k, answer;
int map[MAX][MAX];
int numberCount[MAX];

void find()
{
    int time = 0;
    int hang = 3;
    int yul = 3;

    while (1)
    {
        if (map[r][c] == k)
        {
            answer = time;
            break;
        }
        if (time > 100)
        {
            answer = -1;
            break;
        }

        vector<int> size;
        if (hang >= yul) // 정사각형이거나 세로로긴 형태
        {
            for (int i = 1; i <= hang; i++)
            {
                vector<pair<int, int>> vc;
                memset(numberCount, 0, sizeof(numberCount));
                for (int j = 1; j <= yul; j++)
                    numberCount[map[i][j]]++;
                for (int j = 1; j < MAX; j++)
                {
                    if (numberCount[j] == 0)
                        continue;
                    vc.push_back(make_pair(numberCount[j], j));
                }

                sort(vc.begin(), vc.end());

                for (int j = 1; j <= yul; j++)
                    map[i][j] = 0;

                int index = 1;

                for (int j = 0; j < vc.size(); j++)
                {
                    map[i][index++] = vc[j].second;
                    map[i][index++] = vc[j].first;
                }
                index--;
                size.push_back(index);
            }
            sort(size.begin(), size.end());
            yul = size.back();
        }
        else // 가로로 더 긴꼴
        {
            for (int i = 1; i <= yul; i++)
            {
                vector<pair<int, int>> vc;
                memset(numberCount, 0, sizeof(numberCount));
                for (int j = 1; j <= hang; j++)
                    numberCount[map[j][i]]++;

                for (int j = 1; j < MAX; j++)
                {
                    if (numberCount[j] != 0)
                    {
                        vc.push_back(make_pair(numberCount[j], j));
                    }
                }

                sort(vc.begin(), vc.end());

                for (int j = 1; j <= hang; j++)
                    map[j][i] = 0;

                int index = 1;
                for (int j = 0; j < vc.size(); j++)
                {
                    map[index++][i] = vc[j].second;
                    map[index++][i] = vc[j].first;
                }

                index--;
                size.push_back(index);
            }
            sort(size.begin(), size.end());
            hang = size.back();
        }
        time++;
    }
}

int main()
{

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> map[i][j];
        }
    }

    if (map[r][c] == k)
    {
        answer = 0;
        cout << answer << "\n";
        return;
    }

    find();
    
    cout << answer << "\n";
}
