#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	
	while(cin >> n){
		int a=1, cnt=1;
		
		while(true){
			if(a % n==0){
				cout << cnt << "\n";
				break;
			}else{
				a = (a*10)+1;
				a %= n;
				cnt++;
			}
	    }
	}
	
	return 0;
}