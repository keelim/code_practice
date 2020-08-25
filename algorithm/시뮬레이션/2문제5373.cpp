#include <iostream>
#include <vector>
using namespace std;
void clockwise(vector<vector<char>> &a)
{
    int n = 3;
    // (0, 0) (0, 1) (0, 2)
    // (1, 0) (1, 1) (1, 2)
    // (2, 0) (2, 1) (2, 2)
    //          |
    //          v
    // (2, 0) (1, 0) (0, 0)
    // (2, 1) (1, 1) (0, 1)
    // (2, 2) (1, 2) (0, 2)
    char temp = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[0][2];
    a[0][2] = temp;
    temp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = temp;
}
void U(vector<vector<vector<char>>> &a)
{
    // 0 -> 2 -> 5 -> 4
    vector<vector<char>> temp = a[0];
    a[0] = a[4];
    a[4] = a[5];
    a[5] = a[2];
    a[2] = temp;
    clockwise(a[5]);
    clockwise(a[5]);
    clockwise(a[4]);
    clockwise(a[4]);
    clockwise(a[1]);
    clockwise(a[3]);
    clockwise(a[3]);
    clockwise(a[3]);
}
void F(vector<vector<vector<char>>> &a)
{
    // 1 -> 2 -> 3 -> 4
    vector<vector<char>> temp = a[1];
    a[1] = a[4];
    a[4] = a[3];
    a[3] = a[2];
    a[2] = temp;
    clockwise(a[2]);
    clockwise(a[2]);
    clockwise(a[2]);
    clockwise(a[3]);
    clockwise(a[3]);
    clockwise(a[3]);
    clockwise(a[4]);
    clockwise(a[4]);
    clockwise(a[4]);
    clockwise(a[1]);
    clockwise(a[1]);
    clockwise(a[1]);
    clockwise(a[0]);
    clockwise(a[0]);
    clockwise(a[0]);
    clockwise(a[5]);
}
void L(vector<vector<vector<char>>> &a)
{
    // 0 -> 1 -> 5 -> 3
    vector<vector<char>> temp = a[0];
    for (int i = 0; i < 3; i++)
    {
        a[0][i][0] = a[3][i][0];
        a[3][i][0] = a[5][i][0];
        a[5][i][0] = a[1][i][0];
        a[1][i][0] = temp[i][0];
    }
    clockwise(a[4]);
}
void R(vector<vector<vector<char>>> &a)
{
    // 0 -> 3 -> 5 -> 1
    vector<vector<char>> temp = a[0];
    for (int i = 0; i < 3; i++)
    {
        a[0][i][2] = a[1][i][2];
        a[1][i][2] = a[5][i][2];
        a[5][i][2] = a[3][i][2];
        a[3][i][2] = temp[i][2];
    }
    clockwise(a[2]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<vector<vector<char>>> a;
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'w')));
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'r')));
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'b')));
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'o')));
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'g')));
        a.push_back(vector<vector<char>>(3, vector<char>(3, 'y')));
        while (m--)
        {
            string s;
            cin >> s;
            int k = 1;
            if (s[1] == '-')
                k = 3;

            if (s[0] == 'U')
            {
                U(a);
                for (int i = 0; i < k; i++)
                    R(a);
                for (int i = 0; i < 3; i++)
                    U(a);
            }
            else if (s[0] == 'D')
            {
                U(a);
                for (int i = 0; i < k; i++)
                    L(a);
                for (int i = 0; i < 3; i++)
                    U(a);
            }
            else if (s[0] == 'F')
            {
                F(a);
                for (int i = 0; i < k; i++)
                    R(a);
                for (int i = 0; i < 3; i++)
                    F(a);
            }
            else if (s[0] == 'B')
            {
                F(a);
                for (int i = 0; i < k; i++)
                    L(a);
                for (int i = 0; i < 3; i++)
                    F(a);
            }
            else if (s[0] == 'L')
            {
                for (int i = 0; i < k; i++)
                    L(a);
            }
            else if (s[0] == 'R')
            {
                for (int i = 0; i < k; i++)
                    R(a);
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[0][i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
