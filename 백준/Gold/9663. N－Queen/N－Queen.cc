#include <iostream>
using namespace std;

//퀸을 놓는 방법의 갯수
//퀸은 일직선으로 앞, 뒤, 옆, 대각선 어떤 방향이든 원하는 만큼 이동할 수 있다.
//N by N에 N개의 퀸을 놓자.

//같은 행, 열,대각선 다 이동 가능
//n은 4부터 가능하다.
//행 i, 열 j, 대각선의 y좌표, x좌표의 합은 같다.

int n, ret;
int ans[17];   //각 행에 어떤 열이 선택 되었는지

bool check(int idx){
    for(int i=0; i<idx; i++){
        if(ans[idx] == ans[i]) return false;  //열 체크
        if (abs(idx - i) == abs(ans[idx] - ans[i])) return false; // 대각선에 퀸이 있는 경우  //대각선 체크
    }

    return true;
}

void solve(int idx){ //현재 행, 열
    if(idx == n){ //모든 퀸 놓음
        ret++;
        return;
    }
    
    //열 돌면서 나올 수 있는 모든 경우
    for(int i=0; i<n; i++){ // 모든 열을 탐색
        ans[idx]=i;         //// idx번째 행의 i번째 열에 퀸을 놓아본다
        if(check(idx)){
            solve(idx+1);
            //ans[idx]=-1;
        }
        ans[idx]=-1;
        
    }

}

int main(){

    cin >> n;

    //초기는 -1로 초기화
    for(int i=0; i<n; i++){
        ans[i]=-1;
    }

    solve(0);

    cout << ret;

    return 0;
}