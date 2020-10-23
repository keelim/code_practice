#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>

using namespace std;

int section[301][301];
int visited[301][301];
int primvisited[1000010];
int vertex[10011][10011];
set<int> vertset[1000010];
vector<pair<int, int> > vertvec[1000010];
int dir[4][2]={ {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, height, answer;

void prim () {

    int start=1; primvisited[start]=1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i=0; i < vertvec[start].size (); i++) {
        int next=vertvec[start][i].first, nextvalue=vertvec[start][i].second;
        pq.push (make_pair (nextvalue, next));
    }


    while (!pq.empty ()) {
        int curr=pq.top ().second, currvalue=pq.top ().first; pq.pop ();
        if (primvisited[curr] == 1) continue;
        primvisited[curr]=1; answer+=currvalue;

        for (int i=0; i < vertvec[curr].size (); i++) {
            int next=vertvec[curr][i].first, nextvalue=vertvec[curr][i].second;
            pq.push (make_pair (nextvalue, next));
        }
    }
}


void vertexCalculation (vector<vector<int> > map) {

    for (int y=0; y < map.size (); y++) {
        for (int x=0; x < map.size (); x++) {

            for (int k=0; k < 4; k++) {
                int nx=x + dir[k][0], ny=y + dir[k][1];
                // �� �������� �ٸ� �������� �Ѿ�� �� �߿� ���� �� �̵��� �� ���� ������ ã�´�. �� ��, Ž�� ������ �� ���� ����� �ʰ� �Ѵ�.
                if (nx >= 0 && nx < map.size () && ny >= 0 && ny < map.size () && section[y][x] != section[ny][nx]) {

                    // ������ �켱���� ť�� ���ؼ� �� ���� ��� ���� �̵� ��� �� ���� ���� ����� ���ؼ� �̵��� ���̱� ������ �� �� �ִ� ����� �׳� �� �����ع�����.
                    vertvec[section[ny][nx]].push_back (make_pair (section[y][x], abs (map[y][x] - map[ny][nx])));
                    vertvec[section[y][x]].push_back (make_pair (section[ny][nx], abs (map[y][x] - map[ny][nx])));
                }
            }
        }
    }

    prim ();
}



void bfs (vector<vector<int> > map, int height) {

    // ��� ���� ���鼭 ��ٸ� ���� �� �� �ִ� ������ ���� ���� �������� ����, �湮 ���� �ʴ� ������ �������� ������ ���� �����̹Ƿ� ���ο� �������� ������ش�.
    int secn=0;
    queue<pair<int, int> > q;
    for (int i=0; i < map.size (); i++) {
        for (int j=0; j < map.size (); j++) {
            // �湮 ���� ���� ���� �ٸ� section�� ���� �������� ����ؼ� BFS�� �����ش�.
            if (visited[i][j] == 0) {
                section[i][j]=++secn;
                visited[i][j]=1;

                q.push ({ i, j });
                // ���� Ž�� ������ ��ٸ� ���� �̵��� �� �ִ� ��� ������ ���� ���� �������� ���������.
                while (!q.empty ()) {
                    int x=q.front ().first
                    int y=q.front ().second;
                    q.pop ();
                    for (int k=0; k < 4; k++) {
                        int nx=x + dir[k][0]
                        int ny=y + dir[k][1];
                        if (nx >= 0 && nx < map.size () && ny >= 0 && ny < map.size () && visited[ny][nx] == 0 && abs (map[y][x] - map[ny][nx]) <= height) {
                            section[ny][nx]=secn; visited[ny][nx]=1; q.push (make_pair (nx, ny));
                        }
                    }
                }
            }
        }
    }

    vertexCalculation (map);
}


int solution (vector<vector<int>> land, int height) {
    bfs (land, height);

    return answer;
}
