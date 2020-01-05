#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> tempSet;
    for (auto i = 0; i < 10; i++)
    {
        int temp;
        cin>>temp;
        temp%=42;
        tempSet.insert(temp);
    }
    cout<<tempSet.size()<<"\n";   
}