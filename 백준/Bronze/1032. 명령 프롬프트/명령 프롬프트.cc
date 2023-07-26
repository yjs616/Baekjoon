#include <bits/stdc++.h>
using namespace std;

int n;
string s[50];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	for(int i=0; i<s[0].size(); i++){
		for(int j=0; j<n; j++){
			if(s[0][i] != s[j][i]){     //i로 열 고정 
				s[0][i] = '?';
				break;
			}
		}
		cout << s[0][i]; 		       
	}	
			
	return 0;
}