#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ny, nx, cnt, ret;
char a[23][23];
int visited[30];       //알파벳 갯수만큼
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){

    //cout << "현재 y: " << y << "현재 x : " << x << "현재 cnt : " << cnt << "\n";

    ret = max(ret, cnt);

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || ny >=n || nx<0 || nx>=m) continue;

        int next = a[ny][nx]-'A';
        
        if(visited[next]==0){
            visited[next] = 1;  //방문하지 않았으면 방문처리하고 dfs 재귀
            dfs(ny, nx, cnt+1);
            //dfs끝나면 visited 초기화
            visited[next]=0;
        }
    }

    return;
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    visited[a[0][0]-'A'] = 1;
    dfs(0, 0, 1);

    cout << ret << "\n";

    return 0;
}