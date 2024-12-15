#include <iostream>
using namespace std;

int n, s, cnt;   //cnt : 경우의 수
int arr[23];
int visited[23];
int sum;

void solve(int idx){

    if(sum == s){
        cnt++;
    }

    //종료 조건
    if(idx == n-1) return;

    for(int i= idx+1; i<n; i++){
        sum += arr[i];
        solve(i);
        sum -= arr[i];

    }
}

int main(){

    cin >> n >> s;

    //배열에 숫자 입력하기
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //모든 경우 시작점 잡기
    for(int i=0; i<n; i++){
        sum = arr[i];     //첫번째꺼 더하고 시작
        solve(i);
    }

    cout << cnt << "\n";


    return 0;
}