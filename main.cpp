#include <iostream>
#include <algorithm>
using namespace std;
int map[100001];
int main(){
    int n;
    cin>>n;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        cin>>map[i];
    }

    //a
    int a= 0;
    int a1 = map[0];
    for (int i = 1; i < n; i++) { // 연속된 오름차순
        if(a1<=map[i]){
            a++;
        }
    }
    int b=0;
    int b1 = map[0];
    //b //ㅣ연속된 내림차순
    for (int i = 1; i < n; i++) {

    }

    answer = max(a, b);
    cout<<answer<<'\n';



    return 0;
}