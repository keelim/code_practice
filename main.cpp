#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    int max = 0;

    do{
        // string temp ="";
        
        // for(int i=0; i<numbers.size(); i++){
        //     temp.append(to_string(numbers[i]));
        //     int value = stoi(temp);
        //     if(value>max) max = value;

        // }

        for(int i=0;i<numbers.size();i++){
            cout<<numbers[i];
        }
        cout<<"\n";
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = to_string(max);


    return answer;
}