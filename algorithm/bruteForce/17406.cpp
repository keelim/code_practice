#include <iostream>
#include <vector>

using namespace std;

struct TurnInfo
{
    int R, C, S;
};

int n, m, k, r, c, s, answer;
int map[51][51];
int cmap[51][51];
bool select[6];

vector<TurnInfo> vc;
vector<int> turnOrder;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void copyMap()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cmap[i][j] = map[i][j];
}

int changeDir(int cu)
{
    if (cu == 0)
        return 3;
    else if (cu == 1)
        return 2;
    else if (cu == 2)
        return 0;
    else if (cu == 3)
        return 1;
}

void simulation(TurnInfo T)
{
    /*=======================================================================*/
    /*실제로 배열을 돌려보는 함수.
      1. while문을 통해서 각 라인별이 아닌, 한 번에 처리하는 식으로 구현.
      2. 돌려야 할 사각형의 범위 밖으로 나가는 경우 방향을 바꿔주는 식으로 구현. */
    /*=======================================================================*/

    int Sx = T.R - T.S;
    int Sy = T.C - T.S;
    int Ex = T.R + T.S;
    int Ey = T.C + T.S;
    int Turn_Count = (Ex - Sx) / 2; // 몇 개의 사각형을 돌려줘야 하는지

    for (int i = 0; i < Turn_Count; i++) // 돌려야 할 사각형의 갯수만큼 반복
    {
        int x = Sx;            // x = 시작 X좌표
        int y = Sy;            // y = 시작 y좌표
        int Temp = cmap[x][y]; // 가장 첫 시작점을 Temp에 임시적으로 저장
        int d = 2;             // 0 = 동, 1 = 서, 2 = 남, 3 = 북. 첫 방향은 남쪽 !
        /* 첫 방향을 남쪽으로 잡은 이유 
           - 시계방향으로 배열이 회전되는 것이기 때문에, 이는 어떻게 보면
             자기 자신을 기준으로 반 시계 방향에 있는 값이 자기 자신의 자리에 위치하게 된다.
             즉, 시작점을 기준으로 왼쪽 세로변, 하단 가로변, 우측 세로변, 상단 가로변 순서로 
             움직이면서 값을 설정해 주었다. */

        while (1)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            // (nx, ny) = 위에서 말했듯이, 현재 자기자신을 기준으로 한 칸 왼쪽(반시계방향) 에 있는 좌표

            if (nx == Sx && ny == Sy) // 다시 처음 위치로 돌아오게 된다면
            {
                cmap[x][y] = Temp; // 위에서 저장해둔 임시 저장 값으로 값을 설정 후 종료.
                break;
            }

            if (Sx <= nx && nx <= Ex - i && Sy <= ny && ny <= Ey - i) // 현재 사각형의 범위 내에 있는 좌표라면
            {
                cmap[x][y] = cmap[nx][ny]; // 자기자신의 자리에 반 시계방향에 있는 좌표를 넣어준다.
                x = nx;                    // x값 재설정
                y = ny;                    // y값 재설정
            }
            else
            {
                /* 그렇게, 방향을 따라가다 보면 정해진 사각형의 범위를 벗어나는 경우가 존재함. 
                   그럴 때는 방향을 바꿔준다.
                   남쪽 -> 동쪽 -> 북쪽 -> 서쪽 순으로 ! */
                d = changeDir(d);
            }
        }
        Sx++;
        Sy++;
        /* 그 다음 사각형으로 가기 위한 Sx, Sy값 설정.
           만약, 돌려야 할 사각형의 갯수가 2개이고, 가장 바깥쪽 사각형의 시작점이 (1, 1)이엿다면
           그 다음으로 돌려야 할 사각형의 시작점은 (2, 2)가 될 것이다. 
           즉, Sx++ ,Sy++ */
    }
}

int Calculate()
{
    /*=======================================================================*/
    /*돌려본 배열에서 모든 행에서 최소값을 갖는 행의 값을 return 해주는 함수. */
    /*=======================================================================*/
    int R_Value = 999999999;
    for (int i = 1; i <= n; i++)
    {
        int Sum = 0;

        for (int j = 1; j <= m; j++)
        {
            Sum = Sum + cmap[i][j];
        }
        R_Value = min(R_Value, Sum);
    }
    return R_Value;
}

void dfs(int Cnt)
{
    if (Cnt == k)
    {
        /*===========================================================================*/
        /* 순서를 모두 정했을 경우
           1. 맵을 복사해준다. (원본의 맵 유지를 위해서)
           2. 정한 순서대로 ,실제로 맵을 돌려본다. (함수 : Simulation())
           3. 돌려준 맵에서 각 행의 최소값을 찾아서 Answer값을 갱신.*/
        /*===========================================================================*/
        copyMap();
        for (int i = 0; i < turnOrder.size(); i++)
        {
            int Order = turnOrder[i];
            simulation(vc[Order]);
        }
        answer = min(answer, Calculate());
        return;
    }

    /* 배열을 돌리는 순서를 정하기 위한 (순열 생성을 위한) 반복문. */
    for (int i = 0; i < vc.size(); i++)
    {
        if (select[i] == true)
            continue;
        select[i] = true;
        turnOrder.push_back(i);
        dfs(Cnt + 1);
        turnOrder.pop_back();
        select[i] = false;
    }
}

int main()
{

    answer = 987654321;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    for (int i = 0; i < k; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        vc.push_back({r, c, s});
    }

    //input

    dfs(0);
    cout << answer << "\n";
}
