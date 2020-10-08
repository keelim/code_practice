//
// Created by h0033 on 2020-09-25.
//
#include <string>
char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};

string number_to_n(int num, int n){
    string result;
    if(num == 0) return "0";

    while(num > 0){
        result += number[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

