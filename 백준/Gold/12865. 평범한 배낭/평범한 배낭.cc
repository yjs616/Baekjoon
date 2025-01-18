#include <iostream>
using namespace std;
//n개 물건
//각 물건 무게 w, 가치 v
//최대 k의 무게만 넣을 수 있음
//물건들 가치 최대
int n, k;
int w, v;
int dp[100003]; //인덱스:무게,값:물건 가치 최대값

//넣은 물건 또 넣어도 된다는 없음

int main(){
	
	cin >> n >> k; //물품 수, 버틸 수 있는 무게
	
	for(int i=0; i<n; i++){
		cin >> w >> v; //무게, 가치
		for(int j=k; j>=w; j--){
			dp[j] = max(dp[j], dp[j-w]+v);
		}
	}
	
	cout << dp[k];
	
	return 0;
}