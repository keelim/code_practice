#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> days;
    for(int i=0; i<progresses.size();i++){
        int temp = 100 - progresses[i];
        int count=0;
        while(temp<0){
            temp-=speeds[i];
            count++;
        }
        days.push_back(count);
        // 7 3 9
    }
    for(int i=1; i<days.size();i++){
        if(days[i-1]>days[i]) days[i] = days[i-1];
        // 7 7 9
    }
    int count =1;
    for (int i = 1; i < days.size()-1; i++)
    {
        if(days[i]==days[i-1]){
            count++;
        } else{
            answer.push_back(count);
            count=1;
        }
    }
    answer.push_back(count);
    


    return answer;
}