#include <iostream>
using namespace std;

char board[21][21];
int alpabet[27];
int R, C, ny, nx, ret=0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int num, int cnt){

    ret = max(ret, cnt);

    for(int i=0; i<4; i++){

        ny = y + dy[i];
        nx = x + dx[i];

        if(ny <=0 || ny>R || nx <=0 || nx>C) continue;

        int next = (1 << (int)(board[ny][nx]-'A'));

        //지나지 않았을 때
        if((num & next) == 0){
            dfs(ny, nx, num | next, cnt+1);
        }
    }

    return;
}

int main(){

    cin >> R >> C;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> board[i][j];
        }
    }
    dfs(1, 1, 1 << (int)(board[1][1]-'A'), 1);

    cout << ret << "\n";


    return 0;
}