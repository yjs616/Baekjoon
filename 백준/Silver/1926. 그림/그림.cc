#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, map[503][503], visited[503][503], cnt, maxArea, area=1, ny, nx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x){
    visited[y][x] =1;

    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()){
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >=n || nx<0 || nx >=m || map[ny][nx]==0) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                area++;           
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==1 && !visited[i][j]){
                bfs(i, j);
                cnt++;      //bfs 호출 될 때마다 (그림 갯수)

                if(maxArea < area) maxArea = area;
                area = 1;
            }
        }
    }

    cout << cnt <<"\n";
    cout << maxArea << "\n"; 

    return 0;
}