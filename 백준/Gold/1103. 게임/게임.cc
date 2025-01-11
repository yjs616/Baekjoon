#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char arr[53][53];
int visited[53][53]; //방문한 곳 다시 방문하면 무한번으로 움직일 수 있다
int dp[53][53];    //현재까지 이동한 횟수

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

//최대 몇번 움직일 수 있는지
//방문한 곳을 다시 방문하면 무한대

int solve(int y, int x){
    if(y < 1 || y > n || x < 1 || x > m) return 0;
    if(arr[y][x] == 'H') return 0;
    if(visited[y][x]){
        cout << -1 << "\n";    //무한번 이동 가능
        exit(0);    //메인 함수를 종료 시켜야 함.
    }

    int &ret = dp[y][x];
    if(ret) return ret;     //이미 계산한거 재사용
    
    visited[y][x] = 1;     //방문처리
    for(int i=0; i<4; i++){
        int ny = y + dy[i]* ((int)arr[y][x]-'0');
        int nx = x + dx[i]* ((int)arr[y][x]-'0');

        ret = max(ret, solve(ny, nx) + 1);
    }

    //solve 함수 종료 되면 방문 취소 (다음 경우의 수에 영향을 미치지 않도록 원상복구해주기)
    visited[y][x] = 0;

    return ret;
}

int main(){

    cin >> n >> m;

    //입력 받기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    cout << solve(1, 1);


    return 0;
}