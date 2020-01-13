#include <iostream>

using namespace std;
int memo[41] = {1, 1,};

int fibonacci(int n) {
    if (n <= 1) return memo[n];        // 1 or 0 인 경우 바로 돌려준다.
    else if (memo[n] > 0) return memo[n];    // 기존에 있던 값이면 저장을 한다.
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);    // 없는 값이면 저장을 하면서 돌려준다.
}

int main() {
    int testCase, num;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        cin >> num;
        if (num == 0) cout << "1 0\n";
        else cout << fibonacci(num - 2) << " " << fibonacci(num - 1) << "\n";
    }
    return 0;
}
