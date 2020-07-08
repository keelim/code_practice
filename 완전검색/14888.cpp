#include <iostream>
#include <cmath>

#define MAX 11
using namespace std;

int n;
int arr[MAX];
int Plus, Minus, Multiple, Divide;
int Operator_Num, maxVal, minVal;

void DFS(int pi, int mi, int mul, int div, int Sum, int idx, int cnt)
{
    if (cnt == Operator_Num)
    {
        if (maxVal < Sum)
            maxVal = Sum;
        if (minVal > Sum)
            minVal = Sum;
        return;
    }

    if (pi < Plus)
        DFS(pi + 1, mi, mul, div, Sum + arr[idx], idx + 1, cnt + 1);
    if (mi < Minus)
        DFS(pi, mi + 1, mul, div, Sum - arr[idx], idx + 1, cnt + 1);
    if (mul < Multiple)
        DFS(pi, mi, mul + 1, div, Sum * arr[idx], idx + 1, cnt + 1);
    if (div < Divide)
        DFS(pi, mi, mul, div + 1, Sum / arr[idx], idx + 1, cnt + 1);
}

void solution()
{
    DFS(0, 0, 0, 0, arr[0], 1, 0);
    cout << maxVal << "\n"
         << minVal << "\n";
}

int main(void)
{
    maxVal = -1000000001;
    minVal = 1000000001;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> Plus >> Minus >> Multiple >> Divide;
    Operator_Num = n - 1;

    solution();
}
