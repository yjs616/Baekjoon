#include <bits/stdc++.h>
using namespace std;

string s;
char vowels[10]={'a','e','i','o','u','A','E','I','O','U'};
int cnt,sumCnt;

int main(){
	
	while(true){
		cnt=0;
		getline(cin, s);
		if(s== "#"){
			break;
		}
		for(int i=0; i<s.size(); i++){
			for(char ch : vowels){
				if(s[i] == ch){
					cnt++;
				}
			}
 
		}
		cout << cnt << "\n";				
	}
	
	return 0;
}