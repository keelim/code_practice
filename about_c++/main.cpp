#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
    int n, v, a = 0;
    int* arr = new int[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    cin >> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] = v) //v랑 같으면 a++;
            a++;
    }
    cout << a << "\n";

    return 0;
}