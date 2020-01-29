#include <iostream>
#include <algorithm>
using namespace std;

int input;
int dp[1000001];

int main(){
    cin>>input;

    dp[1] = 0;
    for (auto i = 2; i <= input; i++)
    {
        dp[i] = dp[i-1]+1;
        if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
    }
    cout<<dp[input];
}