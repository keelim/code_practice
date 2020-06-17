#include <iostream>
#include <vector>
using namespace std;
int n, b, c, answer = 0;
vector<int> a;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cin >> b >> c; //입력

    //한 시험장 총감독 1 v[i].size
    // b 총감독 감시수
    // c 부감독 감시수
    // answer 총 감시수

    //총감독수 + answer
    answer += a.size();
    // vector 인원 빼기
    // 부감독 수 구하기
    for (int i = 0; i < n; i++)
    {
        a[i] -= b;
        if (a[i] == 0)
            continue;
        answer += a[i] / c;   //몫
        int temp2 = a[i] % c; //나머지
        if (temp2 > 0)
            answer++;
    }

    cout << answer << "\n"; //출력
    return 0;
}