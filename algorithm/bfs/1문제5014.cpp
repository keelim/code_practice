#include <iostream>
#include <queue>

using namespace std;
int dist[1000001];
bool check[1000001];

int main()
{
    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    queue<int> q;
    q.push(s);
    check[s] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x+u<=f&&!check[x+u]){
            dist[x+u] = dist[x]+1;
            check[x+u]=1;
            q.push(x+u);
        }

        if(x-d>=1&&!check[x-d]){
            dist[x-d] = dist[x]+1;
            check[x-d] = 1;
            q.push(x-d);
        }
    }

    if(check[g]){
        cout<<dist[g]<<"\n";
    } else {
        cout<< "use the stairs\n";
    }

    return 0;
}