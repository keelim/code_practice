#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int testNum;
	vector<int> vc;

	cin >> testNum;
	for (auto i=0; i < testNum; i++) {
		int temp;
		cin >> temp;	
		vc.push_back (temp);
	}
	sort (vc.begin(), vc.end);
	cout << vc[testNum / 2] << "\n";
	
}
