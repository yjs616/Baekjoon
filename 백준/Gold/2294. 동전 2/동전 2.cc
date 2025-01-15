#include <iostream>
#include <algorithm>
using namespace std;

//n가지 동전 적당히 합해서 k원이 되도록
//동전 수는 최대한 적게 
//사용한 동전 최소 갯수 출력
//불가능하면 -1 출력


int n, k, dp[10003];  //동전 종류, 합
int num;
int INF = 987654321;

int main(){

    cin >> n >> k;

    fill(dp, dp+10003, INF);
    dp[0] = 0;

    for(int i=0; i<n; i++){
        cin >> num;   //종류 입력 
        for(int j=num; j<= k; j++){
            dp[j] = min(dp[j], dp[j-num]+1);
        }
    }

    if(dp[k] == INF) cout << -1;
    else cout << dp[k];

    return 0;
}