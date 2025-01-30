#include <iostream>
using namespace std;

int n, k, w, v; 
int dp[100003];    
//물건 N개
//W 무게
//V 가치

//K만큼의 무게만 담으면서 가치 최대화
int main(){

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> w >> v;
        for(int j = k;  j >= w; j--){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }

    cout << dp[k];

}