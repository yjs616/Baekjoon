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
		if(x+T <=M && x-R<m){
			x+=T;
			exeCnt++;
			totalTime++;
		}else if(x+T<=M && x-R>= m){
			x+=T;
			exeCnt++;
			totalTime++;
		}else if(x+T>M && x-R<m){
			x=m;
			totalTime++;
		}else if(x+T>M && x-R>=m){
			x-=R;
			totalTime++;
		}
	} 
	
	cout << totalTime; 
	
	return 0;
}