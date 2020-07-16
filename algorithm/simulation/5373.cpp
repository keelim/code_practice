#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int n;
vector<pair<char, char>> vc;
vector<char> cube[7];

void init()
{
    vc.clear();
    for (int i = 0; i < 7; i++)
    {
        cube[i].clear();
    }
}

// 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

int selectPhase(char where)
{
    if (where == 'U')
        return 1;
    else if (where == 'D')
        return 2;
    else if (where == 'F')
        return 3;
    else if (where == 'B')
        return 4;
    else if (where == 'L')
        return 5;
    else if (where == 'R')
        return 6;
}

void reSet(char where, char dir)
{
    int Phase = selectPhase(where);

    if (dir == '+')
    {
        int Tmp1 = cube[Phase].at(0);
        cube[Phase].at(0) = cube[Phase].at(6);
        cube[Phase].at(6) = cube[Phase].at(8);
        cube[Phase].at(8) = cube[Phase].at(2);
        cube[Phase].at(2) = Tmp1;

        int Tmp2 = cube[Phase].at(1);
        cube[Phase].at(1) = cube[Phase].at(3);
        cube[Phase].at(3) = cube[Phase].at(7);
        cube[Phase].at(7) = cube[Phase].at(5);
        cube[Phase].at(5) = Tmp2;
    }
    else if (dir == '-')
    {
        int Tmp1 = cube[Phase].at(0);
        cube[Phase].at(0) = cube[Phase].at(2);
        cube[Phase].at(2) = cube[Phase].at(8);
        cube[Phase].at(8) = cube[Phase].at(6);
        cube[Phase].at(6) = Tmp1;

        int Tmp2 = cube[Phase].at(1);
        cube[Phase].at(1) = cube[Phase].at(5);
        cube[Phase].at(5) = cube[Phase].at(7);
        cube[Phase].at(7) = cube[Phase].at(3);
        cube[Phase].at(3) = Tmp2;
    }
}

void Change_Cube(char Where, char Dir)
// 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오
{
    if (Where == 'U')
    {
        if (Dir == '+')
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[6].at(0);
            Tmp2 = cube[6].at(1);
            Tmp3 = cube[6].at(2);

            cube[6].at(0) = cube[4].at(0);
            cube[6].at(1) = cube[4].at(1);
            cube[6].at(2) = cube[4].at(2);

            cube[4].at(0) = cube[5].at(0);
            cube[4].at(1) = cube[5].at(1);
            cube[4].at(2) = cube[5].at(2);

            cube[5].at(0) = cube[3].at(0);
            cube[5].at(1) = cube[3].at(1);
            cube[5].at(2) = cube[3].at(2);

            cube[3].at(0) = Tmp1;
            cube[3].at(1) = Tmp2;
            cube[3].at(2) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[6].at(0);
            Tmp2 = cube[6].at(1);
            Tmp3 = cube[6].at(2);

            cube[6].at(0) = cube[3].at(0);
            cube[6].at(1) = cube[3].at(1);
            cube[6].at(2) = cube[3].at(2);

            cube[3].at(0) = cube[5].at(0);
            cube[3].at(1) = cube[5].at(1);
            cube[3].at(2) = cube[5].at(2);

            cube[5].at(0) = cube[4].at(0);
            cube[5].at(1) = cube[4].at(1);
            cube[5].at(2) = cube[4].at(2);

            cube[4].at(0) = Tmp1;
            cube[4].at(1) = Tmp2;
            cube[4].at(2) = Tmp3;
        }
    }
    else if (Where == 'D') // 아랫면
    {
        if (Dir == '+') // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(6);
            Tmp2 = cube[3].at(7);
            Tmp3 = cube[3].at(8);

            cube[3].at(6) = cube[5].at(6);
            cube[3].at(7) = cube[5].at(7);
            cube[3].at(8) = cube[5].at(8);

            cube[5].at(6) = cube[4].at(6);
            cube[5].at(7) = cube[4].at(7);
            cube[5].at(8) = cube[4].at(8);

            cube[4].at(6) = cube[6].at(6);
            cube[4].at(7) = cube[6].at(7);
            cube[4].at(8) = cube[6].at(8);

            cube[6].at(6) = Tmp1;
            cube[6].at(7) = Tmp2;
            cube[6].at(8) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(6);
            Tmp2 = cube[3].at(7);
            Tmp3 = cube[3].at(8);

            cube[3].at(6) = cube[6].at(6);
            cube[3].at(7) = cube[6].at(7);
            cube[3].at(8) = cube[6].at(8);

            cube[6].at(6) = cube[4].at(6);
            cube[6].at(7) = cube[4].at(7);
            cube[6].at(8) = cube[4].at(8);

            cube[4].at(6) = cube[5].at(6);
            cube[4].at(7) = cube[5].at(7);
            cube[4].at(8) = cube[5].at(8);

            cube[5].at(6) = Tmp1;
            cube[5].at(7) = Tmp2;
            cube[5].at(8) = Tmp3;
        }
    }
    else if (Where == 'F')
    {
        if (Dir == '+') // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[1].at(6);
            Tmp2 = cube[1].at(7);
            Tmp3 = cube[1].at(8);

            cube[1].at(6) = cube[5].at(8);
            cube[1].at(7) = cube[5].at(5);
            cube[1].at(8) = cube[5].at(2);

            cube[5].at(8) = cube[2].at(2);
            cube[5].at(5) = cube[2].at(1);
            cube[5].at(2) = cube[2].at(0);

            cube[2].at(2) = cube[6].at(0);
            cube[2].at(1) = cube[6].at(3);
            cube[2].at(0) = cube[6].at(6);

            cube[6].at(0) = Tmp1;
            cube[6].at(3) = Tmp2;
            cube[6].at(6) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[1].at(6);
            Tmp2 = cube[1].at(7);
            Tmp3 = cube[1].at(8);

            cube[1].at(6) = cube[6].at(0);
            cube[1].at(7) = cube[6].at(3);
            cube[1].at(8) = cube[6].at(6);

            cube[6].at(0) = cube[2].at(2);
            cube[6].at(3) = cube[2].at(1);
            cube[6].at(6) = cube[2].at(0);

            cube[2].at(2) = cube[5].at(8);
            cube[2].at(1) = cube[5].at(5);
            cube[2].at(0) = cube[5].at(2);

            cube[5].at(8) = Tmp1;
            cube[5].at(5) = Tmp2;
            cube[5].at(2) = Tmp3;
        }
    }
    else if (Where == 'B') // 뒷면
    {
        if (Dir == '+') // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[1].at(0);
            Tmp2 = cube[1].at(1);
            Tmp3 = cube[1].at(2);

            cube[1].at(0) = cube[6].at(2);
            cube[1].at(1) = cube[6].at(5);
            cube[1].at(2) = cube[6].at(8);

            cube[6].at(2) = cube[2].at(8);
            cube[6].at(5) = cube[2].at(7);
            cube[6].at(8) = cube[2].at(6);

            cube[2].at(8) = cube[5].at(6);
            cube[2].at(7) = cube[5].at(3);
            cube[2].at(6) = cube[5].at(0);

            cube[5].at(6) = Tmp1;
            cube[5].at(3) = Tmp2;
            cube[5].at(0) = Tmp3;
        }
        else
        {
            // 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[1].at(0);
            Tmp2 = cube[1].at(1);
            Tmp3 = cube[1].at(2);

            cube[1].at(0) = cube[5].at(6);
            cube[1].at(1) = cube[5].at(3);
            cube[1].at(2) = cube[5].at(0);

            cube[5].at(6) = cube[2].at(8);
            cube[5].at(3) = cube[2].at(7);
            cube[5].at(0) = cube[2].at(6);

            cube[2].at(8) = cube[6].at(2);
            cube[2].at(7) = cube[6].at(5);
            cube[2].at(6) = cube[6].at(8);

            cube[6].at(2) = Tmp1;
            cube[6].at(5) = Tmp2;
            cube[6].at(8) = Tmp3;
        }
    }
    else if (Where == 'L')
    {
        if (Dir == '+') // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(0);
            Tmp2 = cube[3].at(3);
            Tmp3 = cube[3].at(6);

            cube[3].at(0) = cube[1].at(0);
            cube[3].at(3) = cube[1].at(3);
            cube[3].at(6) = cube[1].at(6);

            cube[1].at(0) = cube[4].at(8);
            cube[1].at(3) = cube[4].at(5);
            cube[1].at(6) = cube[4].at(2);

            cube[4].at(8) = cube[2].at(0);
            cube[4].at(5) = cube[2].at(3);
            cube[4].at(2) = cube[2].at(6);

            cube[2].at(0) = Tmp1;
            cube[2].at(3) = Tmp2;
            cube[2].at(6) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(0);
            Tmp2 = cube[3].at(3);
            Tmp3 = cube[3].at(6);

            cube[3].at(0) = cube[2].at(0);
            cube[3].at(3) = cube[2].at(3);
            cube[3].at(6) = cube[2].at(6);

            cube[2].at(0) = cube[4].at(8);
            cube[2].at(3) = cube[4].at(5);
            cube[2].at(6) = cube[4].at(2);

            cube[4].at(8) = cube[1].at(0);
            cube[4].at(5) = cube[1].at(3);
            cube[4].at(2) = cube[1].at(6);

            cube[1].at(0) = Tmp1;
            cube[1].at(3) = Tmp2;
            cube[1].at(6) = Tmp3;
        }
    }
    else if (Where == 'R')
    {
        if (Dir == '+') // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(2);
            Tmp2 = cube[3].at(5);
            Tmp3 = cube[3].at(8);

            cube[3].at(2) = cube[2].at(2);
            cube[3].at(5) = cube[2].at(5);
            cube[3].at(8) = cube[2].at(8);

            cube[2].at(2) = cube[4].at(6);
            cube[2].at(5) = cube[4].at(3);
            cube[2].at(8) = cube[4].at(0);

            cube[4].at(6) = cube[1].at(2);
            cube[4].at(3) = cube[1].at(5);
            cube[4].at(0) = cube[1].at(8);

            cube[1].at(2) = Tmp1;
            cube[1].at(5) = Tmp2;
            cube[1].at(8) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = cube[3].at(2);
            Tmp2 = cube[3].at(5);
            Tmp3 = cube[3].at(8);

            cube[3].at(2) = cube[1].at(2);
            cube[3].at(5) = cube[1].at(5);
            cube[3].at(8) = cube[1].at(8);

            cube[1].at(2) = cube[4].at(6);
            cube[1].at(5) = cube[4].at(3);
            cube[1].at(8) = cube[4].at(0);

            cube[4].at(6) = cube[2].at(2);
            cube[4].at(3) = cube[2].at(5);
            cube[4].at(0) = cube[2].at(8);

            cube[2].at(2) = Tmp1;
            cube[2].at(5) = Tmp2;
            cube[2].at(8) = Tmp3;
        }
    }
    // U D F B L R
    // U+ U- D- F+ B+ L+ L- R+
    // D+ F- B- R-
    reSet(Where, Dir);
    //PrintCubeState();
    //cout << "===========================================" << endl;
    /*cout << "#########################################" << endl;
    int Cnt = 1;
    for (int i = 0; i < 9; i++)
    {
        cout << Cube[1].at(i);
        if (Cnt == 3)
        {
            cout << endl;
            Cnt = 0;
        }
        Cnt++;
    }
    cout << "#########################################" << endl;
*/
}

int main(void)
{

    int Tc;
    cin >> Tc;

    for (int t = 1; t <= Tc; t++)
    {
        init();
        cin >> n;
        string Inp;

        for (int i = 0; i < n; i++)
        {
            cin >> Inp;
            char a = Inp[0];
            char b = Inp[1];

            //cout << a << b << "\n";
            vc.push_back(make_pair(a, b));
        }

        for (int i = 0; i < 9; i++)
        {
            cube[1].push_back('w'); // 위
            cube[2].push_back('y'); // 아래
            cube[3].push_back('r'); // 앞
            cube[4].push_back('o'); // 뒤
            cube[5].push_back('g'); // 왼
            cube[6].push_back('b'); // 오
        }

        for (int i = 0; i < vc.size(); i++)
        {
            char Where = vc[i].first;
            char Dir = vc[i].second;
            Change_Cube(Where, Dir);
        }

        int Cnt = 1;
        for (int i = 0; i < 9; i++)
        {
            cout << cube[1].at(i);

            if (Cnt == 3)
            {
                cout << endl;
                Cnt = 0;
            }
            Cnt++;
        }
        // 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

        //PrintCubeState();
    }
}
