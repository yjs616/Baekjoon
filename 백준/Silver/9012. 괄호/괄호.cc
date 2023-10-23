#include <iostream>
#include <stack>
using namespace std;

int n;

int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		stack<char> st;
		string s;
		cin >> s;
		
		for(int i=0; i<s.size(); i++){
			if(st.empty()){
				st.push(s[i]);
				continue;
			}
			if(st.top()=='(' && s[i]==')'){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
		
		
		if(st.empty()){
			cout << "YES" << "\n";
		}else{
			cout << "NO" << "\n";
		}
	}

	
	return 0;
}