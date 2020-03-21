#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {if(a>b) return a; return b;}

vector<int> solution(vector<int> heights){
    vector<int> answer;
    answer.push_back(0);

    for(int i=1; i<heights.size();i++){
        int send = heights[i];
        int max = 0;
        for (int j = i-1; j >=0; j++){
            int compare = heights[j];
            if(compare>send){
                max = j+1;
                break;
            }
        }
        answer.push_back(max);
    }

    return answer;
}