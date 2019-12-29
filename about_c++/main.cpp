#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int total;
        cin >> total;
        int count;
        cin >> count;
        int *array = new int[total];
        for (int i = 0; i < total; i++)
        {
            array[i] = -1; //초기화
        }
        for (auto i = 0; i < count; i++)
        {
            int target;
            cin >> target;
            array[target - 1] = 1;
        }
        cout << "#" << (i + 1) << " ";
        for (auto i = 0; i < total; i++)
        {
            if (array[i] == -1)
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
}
