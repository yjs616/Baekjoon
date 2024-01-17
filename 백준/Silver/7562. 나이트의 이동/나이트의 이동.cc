#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int t, l, sy, sx, ey, ex, ny, nx;
int dy[]={-2, -1, 1, 2, 2, 1, -1, -2};
int dx[]={1, 2, 2, 1, -1, -2, -2, -1};
int visited[303][303];

void bfs(int y, int x){
    visited[y][x]=1;

    queue<pair<int, int>> q;
    q.push({y,x});

    while(q.size()){
        tie(y, x) = q.front(); q.pop();

        for(int i=0; i<8; i++){
            ny = y+ dy[i];
            nx = x+ dx[i];

            if(ny<0 || ny>=l || nx<0 || nx>=l) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = visited[y][x]+1;
                q.push({ny, nx});
            }
        }
    }
}

int main(){

    cin >> t;

    while(t >0){

        cin >> l;
        cin >> sy >> sx;
        cin >> ey >> ex;

        //visited 초기화
        memset(visited, 0, sizeof(visited));

        bfs(sy, sx);

        cout << visited[ey][ex]-1 << "\n";    //1부터 시작하니까

        t--;
    }

    return 0;
}