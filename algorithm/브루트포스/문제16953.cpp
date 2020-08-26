#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    for (int i=1; a<=b; i++) {
        if (a == b) {
            cout << i << '\n';
            return 0;
        }
        if (b%10 == 1) {
            b = (b-1)/10;
        } else if (b%2 == 0) {
            b = b/2;
        } else {
            break;
        }
    }
    cout << -1 << '\n';
    return 0;
}
