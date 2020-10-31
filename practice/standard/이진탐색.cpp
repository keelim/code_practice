#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 5005

int d[MAX], n;

bool binarySearch(int x) {

	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2; //�߰� ���� �����´�.

		if (x == d[mid]) return true;
		else if (x > d[mid]) left = mid + 1;//���� �����͸� �̵� �߰� �ڱ��� ����ø���.
		else right = mid - 1;//������ �����͸� �̵� �߰� �ձ��� ����ø���. 
	}

	return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d + n); //������ �ؾ� ����� �� �ִ�. 

	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		if (binarySearch(x)) cout << "�ִ�" << endl;
		else cout << "����" << endl;
	}
}
