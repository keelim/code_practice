#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][1001];
string a, b;

int main() {
	int s1, s2;
	cin >> s1 >> s2;
	cin >> a >> b;

	for (int i = 1; i <= s1; i++) {
		d[i][0] = i;
	}
	for (int j = 1; j <= s2; j++) {
		d[0][j] = j;
	}

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1];
			}
			else {
				d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
			}
		}
	}

	cout << d[s1][s2] << "\n";
	return 0;
}
