//1439
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count1 = 0;
    int count2 = 0;

    if(s[0]=='1') count1++;
    else count2++;

    for(int i=0; i<s.size()-1; i++){
        if(s[i]!=s[i+1]){
            if(s[i+1]=='1') count1++;
            else count2++;
        }
    }

    cout<<min(count1, count2)<<"\n";
}