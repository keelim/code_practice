#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int visited[10001];
vector<P> edge[10001];
/* ���� �˰���
   �켱���� ť�� �̿��Ͽ� �湮�� �� �ִ� ������ ����ġ�� ���� ���� �������� �̵�
   ������ ElogV �� �ð����⵵
*/
int prim () {
	long long ans=0;
	priority_queue<P, vector<P>, greater<P>>pq; // first�� ����ġ second �� ���� minheap 
	pq.push (P (0, 1)); //1�� �������� ����       // ����ġ�� ������������ top���� ���Եȴ�! 

	while (!pq.empty ()) {
		P cur=pq.top ();
		pq.pop ();

		if (visited[cur.second]) //�湮 ���� ǥ�� 
			continue;
		visited[cur.second]=1;

		ans+=cur.first;

		for (int i=0; i < edge[cur.second].size (); i++) { //���� �������� �̵� �� �� �ִ� �湮���� ���� ���� Ǫ�� 
			if (!visited[edge[cur.second][i].second]) {
				pq.push (edge[cur.second][i]);
			}
		}
	}
	return ans;
}

int main (void) {
	int V, E;
	cin >> V >> E;

	for (int i=0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back (P (C, B));
		edge[B].push_back (P (C, A));
	}

	long long result=prim ();
	cout << result;
	return 0;
}
