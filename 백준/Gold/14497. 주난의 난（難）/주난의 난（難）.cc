#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char a[301][301];
int n, m, x1, y1, x2, y2;
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
queue<int> q;

int main() {
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;
    int cnt = 0;
    while(a[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while(!q.empty()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                } else {
                    q.push(1000 * ny + nx);
                }
            }
        }
        q = temp;
    }
    cout << visited[y2][x2] << "\n";
    return 0;
}