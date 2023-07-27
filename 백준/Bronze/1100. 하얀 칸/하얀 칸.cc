#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> s (8, vector<char>(8));
int cnt=0;

int main(){
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin >> s[i][j];
		}
	}
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(i%2==0 && j %2==0 && s[i][j]=='F') cnt++;
			else if(i%2==1 && j%2==1 && s[i][j]=='F') cnt++;
		}
	}
	cout << cnt;
		
	return 0;
}