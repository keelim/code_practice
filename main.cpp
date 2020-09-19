#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int time = 0;
bool visited[200001][2];

int solve(int cPosition, int bPosition) {
    queue <pair<int, int>> q;
    q.push(make_pair(bPosition, 0));

    while (1) {
        cPosition += time;

        if (cPosition > 200000) return -1;
        if (visited[cPosition][time % 2]) return time;

        for (int i = 0, size = q.size(); i < size; i++) {
            int currentPosition = q.front().first;
            int newTime = (q.front().second + 1) % 2;
            int newPosition;
            q.pop();

            newPosition = currentPosition - 1;
            if (newPosition >= 0 && !visited[newPosition][newTime]) {
                visited[newPosition][newTime] = true;
                q.push(make_pair(newPosition, newTime));
            }

            newPosition = currentPosition + 1;
            if (newPosition < 200001 && !visited[newPosition][newTime]) {
                visited[newPosition][newTime] = true;
                q.push(make_pair(newPosition, newTime));
            }

            newPosition = currentPosition * 2;
            if (newPosition < 200001 && !visited[newPosition][newTime]) {
                visited[newPosition][newTime] = true;
                q.push(make_pair(newPosition, newTime));
            }
        }

        time++;
    }
}