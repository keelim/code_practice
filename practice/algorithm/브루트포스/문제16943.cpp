#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string a;
    int b;
    cin >> a >> b;
    int ans = -1;
    sort(a.begin(), a.end());
    do {
        int c = stoi(a);
        if (a[0] != '0' && c < b) {
            if (ans == -1 || ans < c) {
                ans = c;
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}
