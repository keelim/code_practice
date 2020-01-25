#include <iostream>
#include <queue>
using namespace std;
int width;
int height;
int graph[1001][1001];
int day;
queue<>

int dx[] = {
    1,
    -1,
    0,
    0,
};
int dy[] = {0, 0, 1, -1};

void bfs(){

}

int main()
{
    cin >> width >> height;
    memset(graph, -2, sizeof(graph)); //초기화

    for (auto i = 0; i < height; i++)
    {
        for (auto j = 0; j < width; j++)
        {
            cin >> graph[i][j];
        }
    }

    bfs();
}
