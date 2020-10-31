#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 5005

int d[MAX], n;

bool binarySearch(int x) {

	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2; //중간 값을 가져온다.

		if (x == d[mid]) return true;
		else if (x > d[mid]) left = mid + 1;//왼쪽 포인터를 미드 중간 뒤까지 끌어올린다.
		else right = mid - 1;//오른쪽 포인터를 미드 중간 앞까지 끌어올린다. 
	}

	return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d + n); //정렬을 해야 사용할 수 있다. 

	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		if (binarySearch(x)) cout << "있다" << endl;
		else cout << "없다" << endl;
	}
}
