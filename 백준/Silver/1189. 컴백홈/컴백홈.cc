#include <iostream>
using namespace std;

//한수 : 왼쪽 아래점 , 집 :오른쪽 위의 점
//한수 : 지나친 곳 다시 방문 X
//T는 한수가 가지 못함
//거리가 k인 가짓수 구하기

int r, c, k, ret;
char p[7][7];
int visited[7][7];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool check(int y, int x){
    return y==0 && x == c-1;
}

void go(int y, int x, int cnt){
    visited[y][x] = 1;
 
    if(cnt == k){
        if(check(y, x)){
            ret++;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || ny>=r || nx <0 || nx>=c || p[ny][nx]=='T') continue;
        if(!visited[ny][nx]){
            go(ny, nx, cnt+1);
            visited[ny][nx] = 0;
        }
    }

}

int main(){

    cin >> r >> c >> k;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> p[i][j];
        }
    }

    go(r-1, 0, 1);

    cout << ret;

    return 0;
}