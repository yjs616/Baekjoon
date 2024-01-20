#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  

    while(true){
        string s; 
        getline(cin, s);

        stack<int> st;

        if(s==".") break;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i]== '[') st.push(s[i]);
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(s[i]);
            }else if(s[i]==']'){
                if(!st.empty() && st.top()=='[') st.pop();
                else st.push(s[i]);
            }
        }

        if(st.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}