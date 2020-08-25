#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

bool can(bool blind, char from, char to){
    if(from==to) return true;
    if(blind){
        if(from=='R'&&to=='G') return true;
        if(from=='G'&&to=='R') return true;
    }
    return false;
}

int go(vector<string>&a, bool blind=false){
    int n = a.size();
    vector<vector<bool>> check(n, vector<bool>(, false));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!check[i][j]){
                ans++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j]=1;

                while(!q.empty()){
                    int x, y;
                    tie(x, y) = q.fonrt();
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];

                        if(0<nx||ny<0||nx>=n||ny>=m) continue;
                        if(check[nx][ny]) continue;
                        if(can(blind, a[x][y], a[nx][ny])){
                            check[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector(string) a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    } //input

    cout<<go(a)<<" "<<go(a, true)<<"\n";
    return 0;
}