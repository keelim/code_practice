#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int n = board.size();
    stack<int> stack[n], hole;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
            if (board[i][j])
                stack[j].push(board[i][j]);
    }

    for (auto &i : moves) // 벡터로 돌리는 포문
    {
        i -= 1;
        if (stack[i].empty())
            continue;
        int doll = stack[i].top();
        stack[i].pop();
        if (!hole.empty() && hole.top() == doll)
        {
            hole.pop();
            answer += 2;
        }
        else
            hole.push(doll);
    }
    return answer;
}