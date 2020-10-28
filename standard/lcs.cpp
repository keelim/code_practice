#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str1, str2;

int lcs[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	// LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
	str1 = '0' + s1;
	str2 = '0' + s2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}

			// 현재 비교하는 값이 서로 같다면, lcs는 + 1
			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				// 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	/*
	// 검증 코드
	for (int i = 0; i < len1; i++)
	{
	    for (int j = 0; j < len2; j++)
	        cout << lcs[i][j] << " ";
	    cout << endl;
	}
	*/


	int i = str1.size() - 1;
	int j = str2.size() - 1;
	stack<int> stack; // 거꾸로 담기니 stack을 이용

	while (lcs[i][j] != 0) {
		// 경로 추적
		// cout << " i :: " << i << " j :: " << j << endl;

		// 테이블이 같은 넘버링이라면
		// 왼쪽으로 이동
		if (lcs[i][j] == lcs[i][j - 1]) j--;

			// 위쪽으로 이동
		else if (lcs[i][j] == lcs[i - 1][j]) i--;

			// 왼쪽 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1]) {
			stack.push(i);
			i--;
			j--;
		}
	}

	// 길이 출력
	cout << lcs[str1.size() - 1][str2.size() - 1] << '\n';

	// 단어 출력
	while (!stack.empty()) {
		cout << str1[stack.top()];
		stack.pop();
	}
	return 0;
}
