#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string word;
bool goodWord = true;
int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> word;
		
		stack<char> st;
		
		for(char c : word){
			if(!st.empty() && st.top() == c){
				st.pop();
			}else{
				st.push(c);
			}
		}
		
		if(st.empty()){
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
