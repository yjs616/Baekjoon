#include <bits/stdc++.h>
using namespace std;

string str;
int ret=1;
int main(){
	cin >> str;
	for(int i=0; i< str.size()/2; i++){	
		if(str[i] != str[str.size()-1-i]){
			ret = 0;
			break;
		}else{
			ret =1;
		}
	}
	cout << ret;
	
	return 0;
}