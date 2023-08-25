#include <bits/stdc++.h>
using namespace std;
int gabot[15003], n, m, cnt;
int main(){
	cin >> n >> m;
	
	//갑옷 번호 넣기 
	for(int i=0; i<n; i++){
		cin >> gabot[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j = i+1; j<n; j++){
			int sum = gabot[i] + gabot[j];
			
			if(sum == m){
				cnt++;
			}
		}
	}	
	cout << cnt;
		
	return 0;
}