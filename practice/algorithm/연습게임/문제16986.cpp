#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[9][9];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> d[i][j];
        }
    }
    int m = 20;
    vector<vector<int>> a(3);
    a[1].resize(m);
    for (int i=0; i<m; i++) {
        cin >> a[1][i];
        a[1][i] -= 1;
    }
    a[2].resize(m);
    for (int i=0; i<m; i++) {
        cin >> a[2][i];
        a[2][i] -= 1;
    }
    a[0].resize(n);
    for (int i=0; i<n; i++) {
        a[0][i] = i;
    }
    do {
        vector<int> win = {0, 0, 0};
        vector<int> index = {0, 0, 0};
        int p1 = 0;
        int p2 = 1;
        while (true) {
            if (p1 > p2) swap(p1, p2);
            if (index[p1] >= a[p1].size()) break;
            if (index[p2] >= a[p2].size()) break;
            int res = d[a[p1][index[p1]]][a[p2][index[p2]]];
            index[p1] += 1;
            index[p2] += 1;
            if (res == 2) {
                win[p1] += 1;
                if (win[p1] == k) break;
                p2 = 3-p1-p2;
            } else {
                win[p2] += 1;
                if (win[p2] == k) break;
                p1 = 3-p1-p2;
            }
        }
        if (win[0] == k) {
            cout << 1 << '\n';
            return 0;
        }
    } while (next_permutation(a[0].begin(), a[0].end()));
    cout << 0 << '\n';
    return 0;
}
