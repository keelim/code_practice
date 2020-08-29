#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main(void)
{
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    bool flag = prev_permutation(v.begin(), v.end()); //이를 prev_permutation으로 바꾸면 10973번
    if (!flag)
    {
        cout << -1;
        return 0;
    } //사전순으로 마지막이라면

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << ' ';
    }

    return 0;
}