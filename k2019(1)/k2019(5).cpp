#include <string>
#include <vector>
using namespace std;

bool is_possible(int mid, const vector<int> &stones, int k)
{
    int now = -1;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid + 1 > 0)
        {
            if (i - now > k)
                return false;
            now = i;
        }
    }
    if (stones.size() - now > k)
        return false;
    else
        return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;

    int left = 0, right = (int)2e8;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (is_possible(mid, stones, k))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return answer;
}