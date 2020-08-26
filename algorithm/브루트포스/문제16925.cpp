#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
vector<pair<string,int>> a;
vector<char> ans;
string check(string s, string prefix, string suffix) {
    int len = prefix.length();
    for (int i=0; i<len-1; i++) {
        if (s[i] != prefix[i]) {
            return "";
        }
    }
    s[len-1] = prefix[len-1];
    for (int i=0; i<len-1; i++) {
        if (s[n-i-1] != suffix[len-i-1]) {
            return "";
        }
    }
    s[n-len] = suffix[0];
    return s;
}
bool go(int index, string s) {
    if (index == 2*n-2) {
        cout << s << '\n';
        for (int i=0; i<2*n-2; i++) {
            cout << ans[i];
        }
        cout << '\n';
        return true;
    }
    string s1 = check(s, a[index].first, a[index+1].first);
    if (s1.length() > 0) {
        ans[a[index].second] = 'P';
        ans[a[index+1].second] = 'S';
        if (go(index+2, s1)) {
            return true;
        }
    }
    string s2 = check(s, a[index+1].first, a[index].first);
    if (s2.length() > 0) {
        ans[a[index+1].second] = 'P';
        ans[a[index].second] = 'S';
        if (go(index+2, s2)) {
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n;
    a.resize(2*n-2);
    ans.resize(2*n-2);
    for (int i=0; i<2*n-2; i++) {
        string temp;
        cin >> temp;
        a[i] = make_pair(temp, i);
    }
    sort(a.begin(), a.end(), [](const auto &u, const auto &v) -> bool {
        return u.first.length() < v.first.length();
    });
    string s = "";
    for (int i=0; i<n; i++) {
        s += " ";
    }
    go(0, s);
    return 0;
}