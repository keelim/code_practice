#include <iostream>
#include <string>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; i++) {
        string s;
        cin >> s;
        if (s.length() != 8) {
            cout << "#" << i << " " << -1 << "\n";
            continue;
        }

        string year = s.substr(0, 4);
        string month = s.substr(4, 2);
        int iMonth = stoi(month);
        string day = s.substr(7, 2);
        int iDay = stoi(day);

        int end[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;
        if (iMonth == 0 || iMonth > 12) {
            cout << "#" << i << " " << -1 << "\n";
            continue;
        } else if (iDay == 0 || iDay > 31) {
            cout << "#" << i << " " << -1 << "\n";
            continue;
        } else if (iDay > end[iMonth]) {
            cout << "#" << i << " " << -1 << "\n";
            continue;
        }

        cout << "#" << i << " " << year << "/" << month << "/" << day << "\n";


    }


}
