#include <iostream>
#include <queue>
using namespace std;
int n, t;
int x[1000];
int y[1000];
int s[1000];
int dist[1000][1000];
int manhattan(int i, int j) {
    int t1 = x[i] - x[j];
    int t2 = y[i] - y[j];
    if (t1 < 0) t1 = -t1;
    if (t2 < 0) t2 = -t2;
    return t1 + t2;
}
int near(int u) {
    int ans = -1;
    int where = -1;
    for (int i=0; i<n; i++) {
        if (s[i] == 0) continue;
        if (ans == -1 || ans > dist[u][i]) {
            ans = dist[u][i];
            where = i;
        }
    }
    return where;
}
int calc(int u, int v) {
    int ans = dist[u][v];
    if (s[u] == 1 && s[v] == 1) {
        if (ans > t) ans = t;
    }
    int us = near(u);
    int vs = near(v);
    if (us != -1 && vs != -1 && s[us] == 1 && s[vs] == 1) {
        int temp = dist[u][us] + t + dist[vs][v];
        if (ans > temp) ans = temp;
    }
    return ans;
}
int main() {
    cin >> n >> t;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            dist[i][j] = dist[j][i] = manhattan(i, j);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        cout << calc(u, v) << '\n';
    }
    return 0;
}
