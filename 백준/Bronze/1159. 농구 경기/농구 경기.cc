#include <bits/stdc++.h>
using namespace std;

int num;
string name;
vector<string> names;
vector<char> memberlist;
map<char, int> mp;
bool isValue = false;

int main(){
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> name;
		names.push_back(name);
	}
	
	for(int i=0; i<num; i++){
		mp[names[i][0]]++;
	}
	
	for(auto it : mp){
		if(it.second >= 5){
			memberlist.push_back(it.first);
			isValue = true;
		}
	}
	
	if(isValue){
		for(char i : memberlist) cout << i;
	}else{
		cout << "PREDAJA";
	}
	
	
	/*if(memberlist.empty()){
	    cout << "PREDAJA"; 
	}else{
		for(char i : memberlist) cout << i;	
	}*/
	
	return 0;
}