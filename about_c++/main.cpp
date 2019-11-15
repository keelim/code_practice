#include<iostream>
using namespace std;

int main () {
	int first, second;
	cin >> first >> second;
	if (first == 1 && second == 3 || first == 2 && second == 1 || first == 3 && second == 2) {
		cout << "A" << "\n";
	} else {
		cout << "B" << "\n";
	}
		
}