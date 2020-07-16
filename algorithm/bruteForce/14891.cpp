#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

deque<int> sawTooth[4];
vector<pair<int, int>> command;

bool check[4];
int rotateDir[4];

int k;

void input()
{
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++)
        {
            sawTooth[i].push_back(s[j] - '0');
        }
    }
    cin>>k;
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        command.push_back({a,b}); // pair it`s ok this form 
    }
}

int main()
{
    input();
    solve();
    int flag = 1;
    int result = 0;

    for (int i = 0; i < 4; i++)
    {
        if (sawTooth[i][0] == 1)
            result += flag;
        flag *= 2;
    }
    cout << flag;
}