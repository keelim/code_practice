#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;

vector<int> Wheel[4];
vector<pair<int, int>> vc;


int Reverse_Direction(int d)
{
    if (d == 1)
        return -1;
    else
        return 1;
}

void Actual_Turning(int n, int d)
{
    if (d == 1)
    {
        int Tmp = Wheel[n].at(7);
        for (int i = 7; i > 0; i--)
        {
            Wheel[n].at(i) = Wheel[n].at(i - 1);
        }
        Wheel[n].at(0) = Tmp;
    }
    else if (d == -1)
    {
        int Tmp = Wheel[n].at(0);
        for (int i = 0; i < 7; i++)
        {
            Wheel[n].at(i) = Wheel[n].at(i + 1);
        }
        Wheel[n].at(7) = Tmp;
    }
}

void Turn_Wheel(int n, int d)
{
    int nd = Reverse_Direction(d);
    if (n == 0)
    {
        if (Wheel[n].at(2) != Wheel[n + 1].at(6))
        {
            if (Wheel[n + 1].at(2) != Wheel[n + 2].at(6))
            {
                if (Wheel[n + 2].at(2) != Wheel[n + 3].at(6))
                {
                    Actual_Turning(n, d);
                    Actual_Turning(n + 1, nd);
                    Actual_Turning(n + 2, d);
                    Actual_Turning(n + 3, nd);
                }
                else
                {
                    Actual_Turning(n, d);
                    Actual_Turning(n + 1, nd);
                    Actual_Turning(n + 2, d);
                }
            }
            else
            {
                Actual_Turning(n, d);
                Actual_Turning(n + 1, nd);
            }
        }
        else
        {
            Actual_Turning(n, d);
        }
    }
    else if (n == 1)
    {
        if (Wheel[n].at(6) != Wheel[n - 1].at(2))
        {
            Actual_Turning(n - 1, nd);
        }

        if (Wheel[n].at(2) != Wheel[n + 1].at(6))
        {
            if (Wheel[n + 1].at(2) != Wheel[n + 2].at(6))
            {
                Actual_Turning(n, d);
                Actual_Turning(n + 1, nd);
                Actual_Turning(n + 2, d);
            }
            else
            {
                Actual_Turning(n, d);
                Actual_Turning(n + 1, nd);
            }
        }
        else
        {
            Actual_Turning(n, d);
        }
    }
    else if (n == 2)
    {
        if (Wheel[n].at(2) != Wheel[n + 1].at(6))
        {
            Actual_Turning(n + 1, nd);
        }

        if (Wheel[n].at(6) != Wheel[n - 1].at(2))
        {
            if (Wheel[n - 1].at(6) != Wheel[n - 2].at(2))
            {
                Actual_Turning(n, d);
                Actual_Turning(n - 1, nd);
                Actual_Turning(n - 2, d);
            }
            else
            {
                Actual_Turning(n, d);
                Actual_Turning(n - 1, nd);
            }
        }
        else
        {
            Actual_Turning(n, d);
        }
    }
    else if (n == 3)
    {
        if (Wheel[n].at(6) != Wheel[n - 1].at(2))
        {
            if (Wheel[n - 1].at(6) != Wheel[n - 2].at(2))
            {
                if (Wheel[n - 2].at(6) != Wheel[n - 3].at(2))
                {
                    Actual_Turning(n, d);
                    Actual_Turning(n - 1, nd);
                    Actual_Turning(n - 2, d);
                    Actual_Turning(n - 3, nd);
                }
                else
                {
                    Actual_Turning(n, d);
                    Actual_Turning(n - 1, nd);
                    Actual_Turning(n - 2, d);
                }
            }
            else
            {
                Actual_Turning(n, d);
                Actual_Turning(n - 1, nd);
            }
        }
        else
        {
            Actual_Turning(n, d);
        }
    }
}

void Solution()
{
    for (int i = 0; i < vc.size(); i++)
    {
        int N = vc[i].first;
        int D = vc[i].second;

        Turn_Wheel(N, D);
    }

    int Answer = 0;
    if (Wheel[0].at(0) == 1)
        Answer = Answer + 1;
    if (Wheel[1].at(0) == 1)
        Answer = Answer + 2;
    if (Wheel[2].at(0) == 1)
        Answer = Answer + 4;
    if (Wheel[3].at(0) == 1)
        Answer = Answer + 8;

    cout << Answer << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            int Tmp = Inp[j] - '0';
            Wheel[i].push_back(Tmp);
        }
    }
    // 1은 시계방향 -1은 반시계방향
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int Num, Dir;
        cin >> Num >> Dir;
        Num = Num - 1;
        vc.push_back({Num, Dir});
    }

    Solution();

}
