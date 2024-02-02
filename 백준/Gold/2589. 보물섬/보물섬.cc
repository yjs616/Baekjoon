#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int n, m, ny, nx, _max;
char map[53][53];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[53][53];

void bfs(int y, int x){
    visited[y][x] = 1;

    queue<pair<int,int>> q;
    q.push({y, x});

    while(q.size()){
        tie(y, x)= q.front(); q.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny<0 || ny >=n || nx<0 || nx>=m || map[ny][nx]=='W') continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
                _max = max(_max, visited[ny][nx]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (map[i][j] == 'L'){
                bfs(i, j);
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << _max-1 << "\n";


    return 0;
}
