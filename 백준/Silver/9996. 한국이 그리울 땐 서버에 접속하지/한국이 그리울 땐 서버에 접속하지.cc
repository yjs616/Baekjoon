#include <bits/stdc++.h>
using namespace std;
int n;
string pattern, file, pre, suf;

int main(){
	cin >> n >> pattern;
	
	int pos = pattern.find('*');
	pre = pattern.substr(0,pos);
	suf = pattern.substr(pos+1);
	
	for(int i=0; i<n; i++){
		cin >> file;
		
		if(file.size() < pre.size() + suf.size()){
			cout << "NE" << "\n";
		}else{
			if(pre == file.substr(0,pos) && suf == file.substr(file.size()-suf.size())){
				cout << "DA" << "\n";
			}else{
				cout << "NE" << "\n";
			}
		}
	}
			
	return 0;
}