#include <bits/stdc++.h>
using namespace std;
int n;
int eng[30];   //빈배열 
string name;
bool check = true;
int main(){
	cin >> n;
	
	//eng 배열 채우기 
	for(int i=0; i<n; i++){ 
	    cin >> name;
	    int j = name[0]-'a';
	    eng[j]++;
	}
	
	for(int i=0; i<26; i++){
		if(eng[i] >=5){
			cout << (char)(i +'a');
			check=false;
		}
	}
	
	if(check){
		cout << "PREDAJA";
	}
	
	
	return 0;
}