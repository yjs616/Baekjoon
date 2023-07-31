#include <bits/stdc++.h>
using namespace std;
int N, m, M, T, R, exeCnt=0, totalTime=0, x;
int main(){
	cin >> N >> m >> M >> T >> R;
	
	x = m; //초기 x
	
	if(x+T>M && x-R<m){
		totalTime= -1;
		exeCnt = N;
	}
	
	while(exeCnt < N){
		if(x+T <= M){
			x+=T;
			exeCnt++;
			totalTime++;
			continue;
			
		}
		//x+T >M인 경우 
		if(x-R<m){
			x=m;
			totalTime++;
		}else{
			x-=R;
			totalTime++;
		}
	} 
	
	cout << totalTime; 
	
	return 0;
}