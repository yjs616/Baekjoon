#include <bits/stdc++.h>
using namespace std;
int n;
int arr[13];  //0으로 초기화 
int ans[13];  //0으로 초기화 

int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		int j=0;
		while(arr[i] !=0){
			if(ans[j]==0){
				arr[i]--;
			}
			j++;
		}
		while(ans[j] !=0) j++;
		ans[j] = i+1;
	}
	
	for(int i=0; i<n; i++){
		cout << ans[i] << " ";
	}
		
	return 0;
}