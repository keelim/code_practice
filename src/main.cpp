#include <iostream>

using namespace std;
// 전역 변수 잘 사용하기
int n, count;
int col[16];

//배치 가능 여부
bool promising(int a)
{
    int temp = 1;
    bool flag = true;

    while (temp < a && flag)
    {
        //같은 열이거나 대각선이라면 배치 못함
        if (col[a] == col[temp] || abs(col[a] - col[temp]) == a - temp)
            flag = false;
        temp++;
    }

    return flag;
}

void nqueen(int i)
{
    if (promising(i)) //==true 를 사용해도 된다.
    {
        //판 완성
        if (i == n)
            count++;
        else
            //해당 열 배치
            for (int j = 1; j <= n; j++)
            {
                col[i + 1] = j;
                nqueen(i + 1); //재귀 적으로 (백 트랙킹)
            }
    }
}

int main(void)
{
    cin >> n;
    nqueen(0);
    cout << count << "\n";
}
