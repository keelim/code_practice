#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i < commands.size(); i++){
        vector<int> set = commands[i];
        vector<int> temp;
        temp.assign( array.begin() + set[0] - 1, array.begin() + set[1]);

        sort(temp.begin(), temp.end());

        answer.push_back( temp[set[2] - 1]);
    }

    return answer;
}