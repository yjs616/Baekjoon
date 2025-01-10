#include <iostream>
using namespace std;

//연속된 칸을 차지 하는 파이프
//가로, 세로, 대각선으로 회전 가능

//빈칸 : 0, 벽 : 1
//이동 가능한 곳이 모두 빈칸이어야 한다.

//파이프를 이동시킬 수 있는 방법 수 구하기 

int n;
int arr[20][20];
int dp[20][20][3];

bool check(int y, int x, int next_status){
    //가로, 세로인 경우 체크해야 되는 부분
    if(next_status == 0 || next_status ==1) return arr[y][x]== 1 ? false : true; 
    else if(next_status == 2){
        if(arr[y][x] != 1 && arr[y-1][x] != 1 && arr[y][x-1] != 1) return true;
    }
    return false;
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    //초기화는 이미 0으로 다 되었고
    //이후 확정지을 수 있는 초기화는
    dp[1][2][0] = 1;
    //dp[1][3][0] = 1;   //여기는 벽일 수도 있어서 하면 안됨
    //dp[2][3][2] = 1;    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //가로 이동 경우
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][0];
            if(check(i+1, j+1, 2)) dp[i+1][j+1][2] += dp[i][j][0];

            //세로 이동 경우
            if(check(i+1, j, 1)) dp[i+1][j][1] += dp[i][j][1];
            if(check(i+1, j+1, 2)) dp[i+1][j+1][2] += dp[i][j][1];

            //대각선 이동 경우
            if(check(i+1, j+1, 2)) dp[i+1][j+1][2] += dp[i][j][2];
            if(check(i+1, j, 1)) dp[i+1][j][1] += dp[i][j][2];
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][2];

        }
    }

    int ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

    cout << ret;


    return 0;
}