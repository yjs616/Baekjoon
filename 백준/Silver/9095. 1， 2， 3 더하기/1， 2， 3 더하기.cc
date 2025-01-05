#include <iostream>
using namespace std;

int t, n, dp[13];

int main(){

    cin >> t;

    //초기화
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4; i<=11; i++){
        for(int j=1; j<=3; j++){
            dp[i] += dp[i-j];
        }
    }
    while(t--){
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}