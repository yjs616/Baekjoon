#include <bits/stdc++.h>
using namespace std;
int n, m, rowCnt, colCnt, maxRowCnt=0, maxColCnt=0;
char building[53][53];

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> building[i][j];
		}
	}
	
	//행 갯수 세기(열고정) 
	for(int i=0; i<m; i++){
		rowCnt=0; 
		for(int j=0; j<n; j++){
			if(building[j][i] == 'X') break;
			rowCnt++;
		}
		if(rowCnt == n) maxRowCnt++;
	}
	
	//열 갯수 세기(행고정) 
	for(int i=0; i<n; i++){
		colCnt=0;
		for(int j=0; j<m; j++){
			if(building[i][j]=='X') break;
			colCnt++;
		}
		if(colCnt == m) maxColCnt++;
	}
	
	if(maxRowCnt == maxColCnt) cout << maxRowCnt;
	else{
		cout << max(maxRowCnt, maxColCnt);
	}
	return 0;
}