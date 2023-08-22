#include <bits/stdc++.h>
using namespace std;
int n, k;

int main(){
	
	cin >> n >> k;
	
	vector<int> tem(n);
	
	for(int i=0; i<n; i++){
		cin >> tem[i];
	}
	
	int curSum =0;
	int maxSum = 0;
	
	//초기설정 
	for(int i=0; i<k; i++){
		curSum += tem[i];
	}
	maxSum = curSum;
	
	//슬라이딩 윈도우 
	for(int i=k; i<n; i++){
		curSum = curSum + tem[i] - tem[i-k];
		maxSum = max(curSum, maxSum);
	}
	
	cout << maxSum;
		
	return 0;
}