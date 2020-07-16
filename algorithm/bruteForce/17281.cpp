#include <iostream>
#include <vector>
#include <cstring>

#define MAX 50 + 1
#define PLAYER_NUM 10
using namespace std;

int n, answer;
int order[PLAYER_NUM];     // 타순을 저장하기 위한 배열
int game_play[MAX][PLAYER_NUM]; // 각 이닝에서의 선수들의 능력치 저장
bool select[PLAYER_NUM];   // 이미 뽑은 타순인지 판단하기 위한 배열
vector<int> vc;


void game()
{
    /* 실제로 게임을 진행해보기 위한 함수 */
    int Score = 0;
    int Start_Player = 1;
    int Base_State[4];
    /* Base[4]의 의미.
       Base[0] = 홈, Base[1] = 1루, Base[2] = 2루, Base[3] = 3루를 의미한다.
       Base[x] = 0의 의미는 "현재 x루 에는 사람이 없습니다."를 의미하고
       Base[x] = 1의 의미는 "현재 x루 에는 사람이 있습니다."를 의미한다.
       즉, 누군가가 안타, 1루타, 2루타, 3루타 등을 치게 될 경우
       각각의 상황에 맞게 Base[]의 상태를 변경해준다.
    */

    for (int i = 1; i <= n; i++) // 총 N이닝 동안 진행
    {
        int outCount = 0;
        bool nextIning = false;
        for(int i=0;i<4;i++) Base_State[i] = 0;

        while (1)
        {
            for (int j = Start_Player; j < PLAYER_NUM; j++)
            {
                // 순서가 정해진 대로 선수들이 타석으로 출전.
                int Player = game_play[i][order[j]];

                if (Player == 0)
                    outCount++;        // 아웃을 치게되면 Out_Cnt 증가
                else if (Player == 1) // 안타를 치게되면
                {
                    for (int F = 3; F >= 1; F--) // 각 루에 있던 선수들이 한 칸씩 전진하게 된다.
                    {
                        if (Base_State[F] == 1)
                        {
                            if (F == 3) // 3루에 선수가 있었다면
                            {
                                Base_State[F] = 0; // 홈으로 들어가게되고
                                Score++;           // 점수가 1점 ++
                            }
                            else
                            {
                                Base_State[F + 1] = 1; // 3루가 아닌 선수들은 1루씩 전진
                                Base_State[F] = 0;
                            }
                        }
                    }
                    Base_State[1] = 1;
                }
                else if (Player == 2) // 2루타도 마찬가지 원리 !
                {
                    for (int F = 3; F >= 1; F--)
                    {
                        if (Base_State[F] == 1)
                        {
                            if (F == 3 || F == 2)
                            {
                                Base_State[F] = 0;
                                Score++;
                            }
                            else
                            {
                                Base_State[F + 2] = 1;
                                Base_State[F] = 0;
                            }
                        }
                    }
                    Base_State[2] = 1;
                }
                else if (Player == 3) // 3루타도 마찬가지 원리 !
                {
                    for (int s = 3; s >= 1; s--)
                    {
                        if (Base_State[s] == 1)
                        {
                            Base_State[s] = 0;
                            Score++;
                        }
                    }
                    Base_State[3] = 1;
                }
                else // 홈런일 경우
                {
                    for (int F = 1; F <= 3; F++)
                    {
                        if (Base_State[F] == 1)
                        {
                            Base_State[F] = 0;
                            Score++; // 어떤 루에 있던 간에 무조건 홈으로 들어갈 수
                                     // 있으므로 점수++
                        }
                    }
                    Score++;
                }

                if (outCount == 3) // 3Out이 되면 그 다음 이닝으로 넘어간다.
                {
                    Start_Player = j + 1;
                    if (Start_Player == PLAYER_NUM)
                        Start_Player = 1;

                    nextIning = true;
                    break;
                }
            }
            if (nextIning == true)
                break;
            Start_Player = 1;
        }
    }

    answer = max(answer, Score);
}

void dfs(int count)
{
    /* 순열을 구현하기 위한 DFS 함수 부분 */
    if (count == PLAYER_NUM)
    {
        game();
        return;
    }

    for (int i = 1; i < PLAYER_NUM; i++)
    {
        if (select[i] == true)
            continue;
        select[i] = true;
        order[i] = count;
        dfs(count + 1);
        select[i] = false;
    }
}

int main(void)
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < PLAYER_NUM; j++)
            cin >> game_play[i][j];

    /* Game[i][j]의 의미
               Game[1][2] = 3 이라는 예로 설명을 하면
               "1이닝에서 2번 선수는 3(3루타)를 칩니다." 를 의미한다.
            */

    /* 문제의 제약조건. 4번 타자로는 무조건 1번 선수가 출전한다. */
    select[4] = true; // 4번 타자를 이미 골랐습니다.
    order[4] = 1;     // 4번 타자는 1번 입니다.
    dfs(2);           // 순열 구현을 위한 재귀호출

    cout << answer << "\n";
}
