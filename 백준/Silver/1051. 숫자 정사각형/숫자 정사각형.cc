#include <bits/stdc++.h>
using namespace std;

int n, m, s, c=0;
vector<vector<char>> v;       
vector<int> area;

int main(){
	cin >> n >> m;
	v = vector<vector<char>>(n, vector<char>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> v[i][j];
		}
	}
	while(c < min(n, m)){
		for(int i=0; i < n-c; i++){
			for(int j =0; j < m-c; j++){
				int st = v[i][j];
				if(st == v[i][j+c] && st == v[i+c][j] && st == v[i+c][j+c]){
					s=(c+1)*(c+1);
					area.push_back(s);
				}
			}
		}
		c+=1;		
	}
	
	cout << area.back();
	
	return 0;
}