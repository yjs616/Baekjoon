#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[303][2], s[303];

int main(){

    cin >> n;

    for(int i=1; i<=n; i++) cin >> s[i];
    
    //초기화
    dp[1][1] = s[1]; dp[1][2] = 0;
    dp[2][1] = s[2]; dp[2][2] = s[1]+s[2];

    //메모이제이션(점화식)
    for(int i=3; i<=n; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + s[i];
        dp[i][2] = dp[i-1][1] + s[i];
    }

    int ret = max(dp[n][1], dp[n][2]);

    cout << ret;

    return 0;
}