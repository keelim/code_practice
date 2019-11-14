#include<iostream>
using namespace std;

int main () {
	int data;
	cin >> data;
	int answer=0;
	for (auto i=0; i <= data; i++) {
		answer+=i;
	}
	cout << answer;
}
