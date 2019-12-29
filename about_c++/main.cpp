#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (auto i = 1; i <= testCase; i++)
    {
        int first;
        cin >> first;
        int second;
        cin >> second;

        int answer = 0;
        vector<int> array;
        for (auto i = 1; i <= first; i++)
        {
            int temp;
            cin >> temp;
            array.push_back(temp);
        }
        sort(array.begin(), array.end(), greater<int>());

        for (auto i = 0; i < second; i++)
        {
            answer += array.at(i);
        }
        cout << "#" << i << " " << answer << "\n";
    }
}