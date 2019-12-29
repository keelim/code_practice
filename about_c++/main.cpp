#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (auto i = 1; i <= testCase; i++)
    {
        int answer = 0;
        for (auto j = 0; j < 5; j++)
        {
            int temp;
            cin >> temp;
            if (temp < 40)
                temp = 40;
            answer += temp;
        }
        answer /= 5;
        cout << "#" << i << " " << answer << "\n";
    }
}