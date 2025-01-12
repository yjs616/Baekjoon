#include <iostream>
#include <cstring>
using namespace std;

//t초 동안 최대 w만 움직이면서 자두 최대로 받기
//선택 두가지 : 움직인다. 안움직인다.
int t, w, arr[1003];
int dp[1003][2][34];

int solve(int sec, int tree, int move){
    //만약 더이상 움직일 수 없으면 올바른 움직임이 아님
    if(move < 0 ) return -1e9;
    //만약 시간이 다 되었으면 계산 시작
    if(sec == t) return 0;

    //메모이제이션
    int &ret = dp[sec][tree][move];
    if(ret != -1) return ret;     //이전에 계산한 값이 존재하면 재사용

    return ret = max(solve(sec+1, tree, move), solve(sec+1, tree^1, move-1)) + (tree == arr[sec] -1);
}

int main(){
    
    cin >> t >> w;

    for(int i=0; i<t; i++){
        cin >> arr[i];  //1 또는 2 담겨 있음
    }

    //초기화
    memset(dp, -1, sizeof(dp));

    cout << max(solve(0, 0, w), solve(0, 1, w-1));   //안움직이고 시작, 움직이고 시작

    return 0;
}