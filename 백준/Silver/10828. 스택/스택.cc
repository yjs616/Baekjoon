#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
stack<int> st;

int main(){
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		
		if(s== "push"){
			int num;
			cin >> num;
			st.push(num);
			
		}else if(s=="pop"){
			if(st.size()==0){
				cout << "-1" << "\n";
			}else{
				cout << st.top() << "\n";
				st.pop();
			}
		}else if(s=="size"){
			cout << st.size() << "\n";
		}else if(s=="empty"){
			if(st.empty()){
				cout << "1" << "\n";
			}else{
				cout << "0" << "\n";
			}
		}else if("top"){
			if(st.size()==0){
				cout << "-1" << "\n";
			}else{
				cout << st.top() << "\n";
			}			
		}
	}

	
	
	return 0;
}