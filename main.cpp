#include <iostream>
#include <algorithm>
using namespace std;
 
int D[16];
int T[16];
int P[16];
int n, ans;
 
//dp의 경우
int dp(int day){
    if(day == n+1) return 0;
    //날짜가 n+1보다 크다면 -값을 크게 준다.
    if(day > n+1) return -987654321;
    //메모이제이션
    if(D[day] > 0) return D[day];
    //점화식 상담을 안한다 혹은 상담을 한다. 둘 중 하나를 고른다.
    return D[day] = max(dp(day+1), dp(day+T[day])+P[day]); //재귀가 들어감
}

 
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];

    // 입력을 하는 부분
    cout << dp(1)<<"\n";

    return 0;
}

