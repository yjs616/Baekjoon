#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
//지렁이 상하좌우로 이동 
//총 몇마리의 지렁이가 필요한지
//connected component 문제

int T, m, n, k;
int arr[52][52], visited[52][52];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int y, x, ny, nx;

void bfs(int y, int x){
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push({y,x});

    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++){
            ny = y+ dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >=n || nx<0 || nx>=m || !arr[ny][nx]) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    return;
}

int main(){

    cin >> T;
    
    //각 test에 필요한 배추 지렁이 출력
    for(int t=0; t<T; t++){
        cin >> m >> n >> k;
        int cnt=0;

        //arr, visited 초기화
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<k; i++){
            int a, b;
            cin >> a >> b;   //a : x, b : y
            arr[b][a] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] && !visited[i][j]){
                    //1이고 방문하지 않았으면 bfs돌리기
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

    }

    return 0;
}