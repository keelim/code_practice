#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str1, str2;

int lcs[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	// LCS �˰����� ���� �տ� '0'�� �ٿ��ش�.
	str1 = '0' + s1;
	str2 = '0' + s2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}

			// ���� ���ϴ� ���� ���� ���ٸ�, lcs�� + 1
			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				// ���� �ٸ��ٸ� LCS�� ���� ���� Ȥ�� ������ �����´�.
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	/*
	// ���� �ڵ�
	for (int i = 0; i < len1; i++)
	{
	    for (int j = 0; j < len2; j++)
	        cout << lcs[i][j] << " ";
	    cout << endl;
	}
	*/


	int i = str1.size() - 1;
	int j = str2.size() - 1;
	stack<int> stack; // �Ųٷ� ���� stack�� �̿�

	while (lcs[i][j] != 0) {
		// ��� ����
		// cout << " i :: " << i << " j :: " << j << endl;

		// ���̺��� ���� �ѹ����̶��
		// �������� �̵�
		if (lcs[i][j] == lcs[i][j - 1]) j--;

			// �������� �̵�
		else if (lcs[i][j] == lcs[i - 1][j]) i--;

			// ���� ���� ��� �ٸ� �ѹ����̶�� �밢�� �������� �̵�
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1]) {
			stack.push(i);
			i--;
			j--;
		}
	}

	// ���� ���
	cout << lcs[str1.size() - 1][str2.size() - 1] << '\n';

	// �ܾ� ���
	while (!stack.empty()) {
		cout << str1[stack.top()];
		stack.pop();
	}
	return 0;
}
