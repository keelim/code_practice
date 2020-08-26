#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    for (int a0=1; a0<=1000; a0++) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (a[i] != a0+k*i) {
                sum += 1;
            }
        }
        if (ans == -1 || ans > sum) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}
