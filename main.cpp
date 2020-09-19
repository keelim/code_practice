#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 5001

int d[MAX], n;

bool binarySearch(int a) {

    int l = 0, r = n - 1; // 투 포인터 알고리즘으로

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a == d[mid]) return true;
        else if (a > d[mid]) l = mid + 1;
        else r = mid - 1;
    }

    return false;
}

int main() {
    cin>>n;

    for (int i = 0; i < n; i++)
        cin >> d[i];

    sort(d, d + n); //배열 하고 벡터는 다릅니다.

    int t;

    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        if (binarySearch(x)) cout << "exist" << endl;
        else cout << "not exist" << endl;
    }
}