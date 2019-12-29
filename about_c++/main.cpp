#include <iostream>
#include <string>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (auto i = 1; i <= testCase; i++)
    {
        string answer = "";
        string temp;
        cin >> temp;
        temp = temp.end;
        int now = stoi(temp);
        if (now % 2 == 0)
            answer = "Even";
        else
            answer = "Odd";

        cout << "#" << i << " " << answer;
    }
}