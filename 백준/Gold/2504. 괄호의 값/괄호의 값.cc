#include <iostream>
#include <stack>
using namespace std;

string s;
stack<char> st;
int ret;
int tmp = 1;
char pre;

int main(){

    cin >> s;

    //s사이즈만큼 반복
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            st.push(s[i]);
            tmp*=2;
        }else if(s[i]=='['){
            st.push(s[i]);
            tmp*=3;
        }else if(s[i]==')'){
            if(st.empty()){
                ret = 0;
                break;
            }
            else{
                if(st.top()=='('){
                st.pop();
                if(pre !='('){
                    tmp/=2;
                }else{
                    ret+= tmp;
                    tmp/=2;
                }
                }else break;
            }
        }else if(s[i]==']'){
            if(st.empty()){
                ret = 0;
                break;
            }
            else{
                if(st.top()=='['){
                st.pop();
                if(pre != '['){
                    tmp /=3;
                }else{
                    ret+= tmp;
                    tmp/=3;
                }
                }else break;
            }
        }
        //cout << "현재 tmp :" << tmp << "\n";
        //cout << "현재 ret: " << ret << "\n";
        pre = s[i];

    }

    //스택 비워져있으면 유효
    if(!st.empty()) ret=0;
    
    cout << ret;


    return 0;
}