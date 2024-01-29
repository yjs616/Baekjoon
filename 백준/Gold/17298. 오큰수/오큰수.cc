#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> st;
vector<int> arr, ans;

int main(){
    
    ios_base::sync_with_stdio(0); 
	cin.tie(0);

    int n;
    cin >> n;

    arr.resize(n);
    ans.resize(n);


    //배열에 넣기
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty() && (arr[st.top()] < arr[i])){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }

    //스택에 남아있는 인덱스들 처리
    while(!st.empty()){
        ans[st.top()]= -1;
        st.pop();
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}