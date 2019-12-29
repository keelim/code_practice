#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (auto i = 1; i <= testCase; i++)
    {
        set<int, greater<int>> col;
        string line;
        cin >> line;
        for (auto i = 0; i < line.size(); i++)
        {
            col.insert(line[i]);
        }
        cout << "#" << i << " " << col.size() << "\n";
    }
}