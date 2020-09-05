#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n)
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        c += n;
        if (c > 'Z')
        {
            c -= 'Z';
        }
        else if (c > 'z')
        {
            c -= 'z';
        }
        else if (c == ' ')
        {
            continue;
        }
        s[i] = c;
    }

    cout << s;
    return answer;
}