#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#define MAX 1010
using namespace std;

int T, K;
vector<int> V[MAX];
vector<pair<int, int>> vc;

int Reverse(int Dir)
{
    return (Dir == 1) ? -1 : 1;
}

vector<pair<int, int>> Find_Turn_Wheel(int Idx, int Dir)
{
    vector<pair<int, int>> R;
    R.push_back(make_pair(Idx, Dir));
    int Side1 = V[Idx].at(2);
    int Side2;
    int Cur_Dir = Dir;

    for (int i = Idx + 1; i <= T; i++)
    {
        Side2 = V[i].at(6);
        if (Side1 != Side2)
        {
            R.push_back(make_pair(i, Reverse(Cur_Dir)));
            Side1 = V[i].at(2);
            Cur_Dir = Reverse(Cur_Dir);
        }
        else
            break;
    }

    Side1 = V[Idx].at(6);
    Side2 = -1;
    Cur_Dir = Dir;
    for (int i = Idx - 1; i >= 1; i--)
    {
        Side2 = V[i].at(2);
        if (Side1 != Side2)
        {
            R.push_back(make_pair(i, Reverse(Cur_Dir)));
            Side1 = V[i].at(6);
            Cur_Dir = Reverse(Cur_Dir);
        }
        else
            break;
    }

    return R;
}

void Turning(int Idx, int Dir)
{
    if (Dir == 1)
    {
        int Temp = V[Idx].at(7);
        for (int i = 6; i >= 0; i--)
        {
            V[Idx].at(i + 1) = V[Idx].at(i);
        }
        V[Idx].at(0) = Temp;
    }
    else
    {
        int Temp = V[Idx].at(0);
        for (int i = 1; i <= 7; i++)
        {
            V[Idx].at(i - 1) = V[Idx].at(i);
        }
        V[Idx].at(7) = Temp;
    }
}

void Actual_Turning(vector<pair<int, int>> Wheel)
{
    for (int i = 0; i < Wheel.size(); i++)
    {
        int Idx = Wheel[i].first;
        int Dir = Wheel[i].second;
        Turning(Idx, Dir);
    }
}

int main()
{

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < S.length(); j++)
        {
            V[i].push_back(S[j] - '0');
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        vc.push_back(make_pair(a, b));
    }

    for (int i = 0; i < K; i++)
    {
        int W_Idx = vc[i].first;
        int Dir = vc[i].second;

        vector<pair<int, int>> Turn_Wheel;
        Turn_Wheel = Find_Turn_Wheel(W_Idx, Dir);
        Actual_Turning(Turn_Wheel);
    }

    int Cnt = 0;
    for (int i = 1; i <= T; i++)
        if (V[i].at(0) == 1)
            Cnt++;

    cout << Cnt << endl;

    return 0;
}
