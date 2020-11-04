#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int answer = 0;

int main(void) {
	int n, length, weight, t;
	cin >> n >> length >> weight;
	int answer = 0;
	queue<pair<int, int>> q;
	vector<int> waiting_trucks(n);
	vector<int> arrived_trucks;
	int sum = 0;
	
	for (int i = 0; i < n; i++)  cin >> waiting_trucks[i];
	

	while (arrived_trucks.size() < n) {
		answer+=1;
		int front_truck = 0;

		if (!q.empty()) {
			if (q.front().second == answer) {
				int z = q.front().first;
				arrived_trucks.push_back(z);
				sum -= z;
				q.pop();
			}
		}
		if (waiting_trucks.size() > 0) {
			front_truck = waiting_trucks.front();
			if (sum + front_truck <= weight) {
				sum += front_truck;
				waiting_trucks.pop();
				q.push(make_pair(front_truck, answer + length));
			}
		}

	}
	cout << answer;

}
