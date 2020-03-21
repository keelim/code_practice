#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<pair<int, int>> hello; 

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first>b.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for(int i=0; i<priorities.size();i++){
        hello.push_back(make_pair(priorities[i], i));
    }
    hello[location] = make_pair(priorities[location], -1);
    sort(hello.begin(), hello.end(), compare);


    for(int i=0; i<hello.size(); i++){
        cout<<hello[i].first<<hello[i].second<<"\n";
        if(hello[i].second == 1){
            answer = i+1;
        }
    }

    
    return answer;
}