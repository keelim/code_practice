#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, oper;
int answer = -987654321987654321;
int num[21], operArr[21];

int calc(int n1, int n2, char c)
{
    if (c == '+')
        return n1 + n2;
    else if (c == '-')
        return n1 - n2;
    else if (c == '*')
        return n1 * n2;
}

void dfs(int index, int result)
{
    if (index >= oper)
    {
        answer = max(answer, result);
        return;
    }

    int cuResult = calc(result, num[index + 1], operArr[index]);
    dfs(index + 1, cuResult);

    if (index + 1 < oper)
    {
        int afterResult = calc(num[index + 1], num[index + 2], operArr[index + 1]);
        int cuResult = calc(result, afterResult, operArr[index]);
        dfs(index + 2, cuResult);
    }
}

int main()
{

    cin >> n;
    int index1 = 0;
    int index2 = 0;

    string Inp;
    cin >> Inp;
    for (int i = 0; i < Inp.length(); i++)
    {
        if (i % 2 == 0)
            num[index1++] = Inp[i] - '0';
        else
            operArr[index2++] = Inp[i];
    }
    oper = n / 2;

    if (n == 1)
    {
        cout << num[0] << "\n";
        return;
    }
    else if (n == 3)
    {
        cout << calc(num[0], num[1], operArr[0]) << "\n";
        return;
    }

    dfs(0, num[0]);
    cout << answer << "\n";
}
