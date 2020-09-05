#include <iostream>
#include <vector>


using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    vector<int> vc(a);

    for(int i=0; i<a; i++){
        cin>>vc[i];
    } //input
    int answer = 0;
    for(int i=0; i<vc.size(); i++){
        int sum = 0;
        for(int j=i; j<vc.size(); j++){
            sum+=vc[j];
            if(sum == b) answer++;
            if(sum>b) break;
        }
    }

    return 0;
}