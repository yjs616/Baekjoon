#include <bits/stdc++.h>
using namespace std;
string s;
int engNum;
map <char,int> mp;

int main(){
	cin >> s;
	for(int i=0; i<s.size(); i++){
		mp[s[i]]++;
	}
	
	for(int i=97; i<= 122; i++){
		for(auto it : mp){
			if(char(i) ==it.first){
				engNum = it.second;
				break;
			}else{
				engNum =0;
			}
		}
		cout << engNum << " ";
	}
	
	return 0;
}