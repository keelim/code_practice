#include <iostream>

using namespace std;
int map[10];
int main(){
    int t;
    cin>>t;
    for(int s = 1; s<=t; s++){

        for(int i=0; i<10; i++){
            cin>>map[i];
        }
        int answer = 0;
        for(int i=0; i<10; i++){
            if(map[i]%2!=0) answer+=map[i];
        }
        cout<<"#"<<
    }
    return 0;
}