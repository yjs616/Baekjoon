#include <bits/stdc++.h>
using namespace std;

bool visitedStd[1001];
int maxCnt=-1;
int ansStd;
int n;
int main(){
	cin >> n;
	vector<vector<int>>v (n, vector<int>(5));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			cin >> v[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		memset(visitedStd, 0, sizeof(visitedStd));
		int cnt =0;		
		//돌아가면서 세기 
		for(int j=0; j<5; j++){
			int std = v[i][j];            //기준 잡기 
			for(int k=0; k<n; k++){
				if(i != k && std==v[k][j]){
					if(!visitedStd[k]){
						visitedStd[k] = 1;    //중복 방지 
						cnt++;
					}
				}
			}
			if(maxCnt < cnt){
				maxCnt = cnt;
				ansStd = i+1;          //학생번호는 행에 1을 더하면 됨. 
			} 
			
		}
	}	
	cout << ansStd;
	
	return 0;
} 