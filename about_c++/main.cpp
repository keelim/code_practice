#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector<int> vc;
    int total=0;
    for (auto i=0; i < 9; i++) {
        int temp;
        cin >> temp;
        vc.push_back (temp);
        total+=temp;
    }
    int pointer1=0;
    int pointer2=pointer1 + 1;
    while (total - (vc.at (pointer1) + vc.at (pointer2)) != 100) {
        pointer2++;
        if (pointer2 >= 9) {
            pointer1++;
            pointer2=pointer1 + 1;
        }
    }

    vc.erase (vc.begin () + pointer1);
    vc.erase (vc.begin () + pointer2 - 1);

    sort (vc.begin (), vc.end ());
    for (auto i=0; i < 7; i++) {
        cout << vc.at (i) << "\n";
    }
}