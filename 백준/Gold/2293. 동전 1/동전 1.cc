#include <iostream>
#include <algorithm>
using namespace std;

//동전 가치의 합이 k원이 되도록 하는 경우의 수를 구해라.
//이번엔 최소가 아니라 경우의 수 구하는 문제임

int n, k, num;  //종류, 합
int dp[10003]; //경우의 수를 저장한다.

int main(){

    cin >> n >> k;

    dp[0]=1; 

    for(int i=0; i<n; i++){
        cin >> num;
        for(int j=num; j<=k; j++){ //j는 합을 의미
            dp[j] += dp[j-num];
        }
    }

    cout << dp[k];
    return 0;
}