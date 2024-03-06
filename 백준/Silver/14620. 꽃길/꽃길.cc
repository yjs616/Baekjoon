#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, field[14][14], visited[14][14], ret=INF;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void eraseFlower(int y, int x){
    visited[y][x] = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 0;
    }
}

//꽃을 놓고 합을 더하자
int setFlower(int y, int x){
    visited[y][x] = 1;
    int s = field[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 1;
        s += field[ny][nx];
    }
    return s;
}

//꽃을 놓을 수 있는가?
bool check(int y, int x){
    //방문한거면 false
    if(visited[y][x]) return false;
    //방문하지 않은거면 범위 확인 : 범위 벗어나면 false;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx <0 || nx>=n || visited[ny][nx]){
            return false;
        }
    }

    return true;
}


void flower(int cnt, int sum){
    if(cnt == 3){
        ret = min(ret, sum);
        return;             //종료
    }

    //꽃 놓을 수 있다면 밭에서 꽃 놓을 곳 하나 선택
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i, j)){
                flower(cnt+1, sum+setFlower(i, j));
                //재귀 종료되면서 놓여진 꽃 치워야함
                eraseFlower(i, j);
            }
        }
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> field[i][j];
        }
    }

    flower(0, 0);

    cout << ret << "\n";

    return 0;
}