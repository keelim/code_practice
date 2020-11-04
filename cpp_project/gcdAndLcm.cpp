#include <vector>
#include <algorithm>
// #include <numeric>  c++ 17 에서 사용은 할 수있음
using namespace std;

int euclidean (int a, int b) {
    return b ? euclidean (b, a % b) : a;
}

int lcm (int a, int b) {
    return a * b / euclidean (a, b);
}

int solution (vector<int> arr) {
    sort (arr.begin (), arr.end (), greater<int> ());
    int answer=arr[0];
    int arrSize=arr.size ();

    for (int i=1; i < arrSize; i++)
        answer=lcm (answer, arr[i]);

    return answer;
}