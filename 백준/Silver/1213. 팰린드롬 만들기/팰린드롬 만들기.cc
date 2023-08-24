#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
string name;
int change,center;
int main(){
	cin >> name;
	
	for(int i=0; i<name.size(); i++){
		mp[name[i]]++;
	}
	
	int j=0;		
	for(auto it : mp){
		int cnt = it. second;		
		while(cnt >=2){
			name[j] = it.first;
			name[name.size()-1-j] = it.first;
			j++;
			cnt-=2;
		}
		
		if(cnt ==1){
			change++;
			if(change >1){
				name = "I'm Sorry Hansoo";
				break;
			}
			center = it.first;
			name[name.size()/2] = center;
		}
	}		
	cout << name << "\n";		
	return 0;
}