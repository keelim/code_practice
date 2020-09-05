#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 9
using namespace std;

int N, M;
bool visited[MAX];
int arr[MAX];

vector<int> vc;

void go(int Idx, int Cnt)
{
    if (Cnt == M)
    {
        for (int i = 0; i < vc.size(); i++)
        {
            cout << vc[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = Idx; i < N; i++)
    {
        if (visited[i] == true)
            continue;
        visited[i] = true;
        vc.push_back(i + 1);
        go(i, Cnt + 1);
        vc.pop_back();
        visited[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    go(0, 0);

    return 0;
}
