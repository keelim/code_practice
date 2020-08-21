#include <iostream>

using namespace std;
#define MAX 8 + 1
int n, m;
int arr[MAX];
bool visited[MAX];
void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            func(cnt + 1);
            visited[i] = false;
        }
}
int main(void)
{
    cin >> n >> m;
    func(0);
    return 0;
}
// 증가번호


/* bool c[10]; int a[10];
void go(int index, int n, int m){
    if(index==m){
        return ;
    }

    for(int i=1; i<=n; i++){
        if(c[i]) continue;
        c[i] = true; a[index]  =i;
        go(index+1, n, m);
        c[i] = false;
    }
} */

//nm2 //오름차순

int a[10];

void go2(int index, int selected, int n, int m){
    if(selected == m){
        //수열 출력
        return ;
    }

    if(index>n) return ;
    a[selected] = index;
    go2(index+1, selected+1, n, m);
    a[selected] = 0;
    go2(index+1, selected, n, m);
}

bool c[10]; int a[10];
void go3(int index, int n, int m){
    if(index==m){
        return ;
    }

    for(int i=1; i<=n; i++){
        // if(c[i]) continue;
        c[i] = true; a[index]  =i;
        go(index+1, n, m);
        c[i] = false;
    }
}

void go4(int index, int start, int n, int m){
    if(index==m){
        return ;
    }

    for(int i=start; i<=n; i++){
        c[i] =1; a[index] = i;
        go(index+1, i, n, m);
        c[i] = false;
    }
}

