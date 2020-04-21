#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vc;
int total = 0;

int main()
{
    
    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        vc.push_back(temp);
        total += temp;
    }
    int pointer1 = 0;
    int pointer2 = pointer1 + 1;
    while (total - (vc.at(pointer1) + vc.at(pointer2)) != 100)
    {
        pointer2++;
        if (pointer2 >= 9)
        {
            pointer1++;
            pointer2 = pointer1 + 1;
        }
    }

    vc.erase(vc.begin() + pointer1);
    vc.erase(vc.begin() + pointer2 - 1);

    sort(vc.begin(), vc.end());
    for (int i = 0; i < 7; i++)
    {
        cout << vc[i] << "\n";
    }
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