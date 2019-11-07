#include <iostream>
using namespace std;

int main () {
	int temp;
	cin >> temp;
	int answer = 0;
	while (temp != 0) {
		answer+=temp % 10;
		temp/=10;
	}
	cout << answer << "\n";
	
}
