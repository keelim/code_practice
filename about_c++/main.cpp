#include<iostream>
using namespace std;

int main () {
	for (auto i=0; i < 5; i++) {
		for (auto j=0; j < 5; j++) {
			if (i == j)
				cout << "#";
			else
				cout << "+";
		}
	}
}
