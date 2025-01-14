#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//x가 3으로 나눠떨어지면 3으로 나눈다.
//x가 2로 나눠 떨어지면 2로 나눈다.
//1을 뺀다.

//이게 top-down이 편한지, bottom-up이 편한지 생각해보자

//3개 이용해서 1 만들기 연산 횟수 최솟값 출력하기
//1로 나누는 방법에 포함되어 있는 수 출력하기

//출력값을 보니 top-down으로 가자.
int n;
int dp[1000003];
int path[1000003];  //i로 오기 직전의 숫자 저장
const int INF = 987654321;


int main(){
    cin >> n;

    memset(dp, INF, sizeof(dp));

    dp[1] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1; //1을 더하는 이유는 연산에 대한 횟수 증가이다.
        path[i] = i-1;
        if(i % 3 == 0 && dp[i] > dp[i/3]+1){
            dp[i] = min(dp[i], dp[i/3] +1);
            path[i] = i / 3;
        }    
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = min(dp[i], dp[i/2] +1);
            path[i] = i / 2;
        }
    }

    cout << dp[n] << "\n";

    vector<int> v;
    for(int i= n; i > 0; i = path[i]){
        v.push_back(i);
    }

    for(int i : v){
        cout << i << " ";
    }
    
    return 0;
}