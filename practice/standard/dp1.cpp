#include <iostream>
using namespace std;

int map[100], d[10001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 1; i <= k; i++) {
		d[i] = -1;
		for (int j = 0; j < n; j++) {
			if (map[j] <= i) {
				if (d[i - map[j]] < 0) continue;
				if (d[i] < 0) d[i] = d[i - map[j]] + 1;
				else if (d[i - map[j]] + 1 < d[i]) d[i] = d[i - map[j]] + 1;
			}
		}
	}

	cout << d[k] << "\n";
	return 0;
}
