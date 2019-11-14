#include<iostream>
using namespace std;

int main () {
	int testCase;
	cin >> testCase;
	for (auto i=1; i <=testCase; i++) {
		int first;
		int second;
		cin >> first, cin >> second;
		cout << "#" << i << " " << first / second << " " << first % second << "\n";	
	}
}
