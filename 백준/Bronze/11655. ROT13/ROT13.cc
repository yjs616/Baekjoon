#include <bits/stdc++.h>
using namespace std;
string s;
char ret[103];
int main(){
	getline(cin, s);
		
	for(int i=0; i<s.size(); i++){
				
		if(s[i]-'A'>=0 && s[i]-'A'<26){
			if('Z'-s[i] <13){
				int part = 13 - ('Z'-s[i]);
				ret[i] = 'A' + (part-1);
			}else{
				ret[i] = s[i] + 13;
			}			
		}else if(s[i]-'a'>=0 && s[i]-'a'<26){
			if('z'-s[i] <13){
				int part = 13 - ('z'-s[i]);
				ret[i] = 'a'+ (part-1);
			}else{
				ret[i] = s[i]+13;
			}		
		}else{
			ret[i] = s[i];
		}
		cout << ret[i];
	}
	
	return 0;
}