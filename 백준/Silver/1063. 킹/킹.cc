#include <bits/stdc++.h>
using namespace std;
string kingPos, stonePos, direction;
int cnt, kx, ky, sx, sy;
int dx[8]={1, -1, 0, 0, 1, -1, 1, -1};
int dy[8]={0, 0, -1, 1, 1, 1, -1, -1};

bool attempmove(int dir){
	int mkx = kx + dx[dir];
	int mky = ky + dy[dir];
	int msx = sx;
	int msy = sy;
	
	if(mkx <0 || mkx >7 || mky <0 || mky>7){
		return false;
	}
	if(mkx == msx && mky== msy){
		msx += dx[dir];
		msy += dy[dir];
		if(msx <0 || msx >7 || msy <0 || msy>7){
			return false;
		}
	}
	
	kx = mkx; ky= mky;
	sx = msx; sy = msy;
	
	return true;
}

int main(){
	//1. 왕, 돌 위치 입력 받기 
	cin >> kingPos >> stonePos >> cnt;
	
	//2. 왕, 돌 위치 -> 인덱스화 
	kx = kingPos[0] - 'A';     //열 
    ky = kingPos[1] - '1';     //행 

    sx = stonePos[0] - 'A';
    sy = stonePos[1] - '1';
    
	//3. 왕, 돌 움직임 
	for(int i=0; i<cnt; i++){
		cin >> direction;
		
		if(direction == "R"){
			if(!attempmove(0)) continue;
		}else if(direction == "L"){
			if(!attempmove(1)) continue;
		}else if(direction == "B"){
			if(!attempmove(2)) continue;
		}else if(direction == "T"){
			if(!attempmove(3)) continue;
		}else if(direction == "RT"){
			if(!attempmove(4)) continue;
		}else if(direction == "LT"){
			if(!attempmove(5)) continue;
		}else if(direction == "RB"){
			if(!attempmove(6)) continue;
		}else if(direction == "LB"){
			if(!attempmove(7)) continue;
		}
	}
	
	//4. 왕, 돌 인덱스 -> 문자화 
	cout << char('A' + kx) << char('1' + ky) << "\n";
    cout << char('A' + sx) << char('1' + sy) << "\n";
	
	return 0;
}