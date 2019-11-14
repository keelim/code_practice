#include<iostream>
using namespace std;

int main () {
	int aint;
	cin >> aint;
	int answer=1;
	for (auto i=0; i <= aint; i++) {
		cout << answer << " ";
		answer*=2;
	}
}
