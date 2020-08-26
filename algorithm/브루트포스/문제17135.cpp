#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n, m, d;
int a[20][20];
int b[20][20];
int calc(int l1, int l2, int l3) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            a[i][j] = b[i][j];
        }
    }
    int ans = 0;
    while (true) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cnt += a[i][j];
            }
        }
        if (cnt == 0) break;
        vector<pair<int,int>> deleted(3, make_pair(-1,-1));
        vector<int> robot = {l1, l2, l3};
        for (int k=0; k<3; k++) {
            int rx = n, ry = robot[k];
            int x, y, dist;
            x = y = dist = -1;
            for (int j=0; j<m; j++) {
                for (int i=0; i<n; i++) {
                    if (a[i][j] != 0) {
                        int dx = rx-i;
                        int dy = ry-j;
                        if (dx < 0) dx = -dx;
                        if (dy < 0) dy = -dy;
                        int dd = dx+dy;
                        if (dd <= d) {
                            if (dist == -1 || dist > dd) {
                                x = i;
                                y = j;
                                dist = dd;
                            }
                        }
                    }
                }
            }
            deleted[k] = make_pair(x, y);
        }
        for (auto &p : deleted) {
            if (p.first == -1) continue;
            int x, y;
            tie(x, y) = p;
            if (a[x][y] != 0) {
                ans += 1;
            }
            a[x][y] = 0;
        }
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<m; j++) {
                if (i == 0) {
                    a[i][j] = 0;
                } else {
                    a[i][j] = a[i-1][j];
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m >> d;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> b[i][j];
        }
    }
    int ans = 0;
    for (int l1=0; l1<m; l1++) {
        for (int l2=l1+1; l2<m; l2++) {
            for (int l3=l2+1; l3<m; l3++) {
                int temp = calc(l1,l2,l3);
                if (ans < temp) ans = temp;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
