#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    vector<int> vc;
    cin >> temp;
    for (int i = 1; i <= temp; i++)
    {
        vc.push_back(i);
    }

    sort(vc.begin(), vc.end());

    do
    {
        for (int i = 0; i < vc.size(); i++)
        {
            cout << vc[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(vc.begin(), vc.end()));
}