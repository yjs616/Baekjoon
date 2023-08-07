#include <bits/stdc++.h>
using namespace std;
string num;
int cnt;
int main(){
	
	while(true){
		cnt =0;
		cin >> num;
		
		if(num =="0"){
			break;
		}
		for(int i=0; i< num.size()/2; i++){
					
			if(num[i]==num[num.size()-1-i]){
				cnt++;
			}
		}
		if(cnt == num.size()/2){
			cout << "yes"<<"\n";
		}else{
			cout << "no" << "\n";
		}
	}
		
	return 0;
}