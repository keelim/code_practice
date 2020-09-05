#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 8 + 1
int N, M;
int arr[MAX];
int a[MAX];
bool visited[MAX];
void func(int cnt, int start)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i < N; i++)
    {
        if (visited[i])
            continue;

        visited[i] = 1;
        arr[cnt] = a[i];
        func(cnt + 1, start+1);
        visited[i] = 0;
    }
}
int main(void)
{
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin>>a[i];
    }
    sort(a, a+M);

    func(0, 0);
    return 0;
}
