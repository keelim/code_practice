#include "bits/stdc++.h"
#define INF 987654321
using namespace std;

int node, edge, start;
int dist[20010];
vector<pair<int, int>> mapp[20010];


void disktra() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0)); //cost, node
    dist[start] = 0;

    while (pq.empty() == 0) {
        int x = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        for (int i = 0; i < mapp[x].size(); i++) {
            int nx = mapp[x][i].first;
            int ncost = mapp[x][i].second;

            if (dist[nx] > cost + ncost) {
                dist[nx] = cost + ncost;
                pq.push(make_pair(-dist[nx], nx));
            }
        }
    }

    for (int i = 1; i <= node; i++) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}

int main() {
    cin >> node >> edge >> start;
    for (int i = 0; i < edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mapp[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= node; i++)
        dist[i] = INF;

    disktra();

    return 0;
}