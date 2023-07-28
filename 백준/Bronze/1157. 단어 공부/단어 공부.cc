#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000003];
map<char, int> mp;

int maxCnt=0;
char result='?';

int main(){
	cin >> s;
	//1	 
	for(int i=0; i<s.size(); i++){
		c[i] = (char)toupper(s[i]);
		//맵에 넣고 value 증가 
		mp[c[i]]++; 
	}
	//2
	for(auto it : mp){
		if(it.second > maxCnt){
			maxCnt = it.second;
			result = it.first;
		}else if(it.second == maxCnt) result='?';
	}
	cout << result;

	return 0;
}