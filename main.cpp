#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp;

    while (n > 0)
    {
        temp = n % 3;
        if (temp == 0) n = (n / 3) - 1;
        else n /= 3;

        answer = "412"[temp] + answer;
    }

    return answer;
}
