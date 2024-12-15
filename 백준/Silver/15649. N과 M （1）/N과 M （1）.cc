#include <iostream>
#include <vector>
using namespace std;

int n, m, visited[10];
vector<int> ans;


void printNum(){
    for(int i: ans){
        cout << i << " ";
    }
    cout << "\n";
}


void solve(int cur, int cnt){
    visited[cur]=1;
    ans.push_back(cur);

    if(cnt == m){
        //cout << "실행됨" << "\n";
        printNum();
        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i] != 1){
            solve(i, cnt+1);
            visited[i]=0;
            ans.pop_back();
        }
    
    }
    //visited[cur]=0;
    //ans.pop_back();
    //cnt-=1;
    
}

int main(){

    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        solve(i, 1);
        //memset(visited, 0, sizeof(visited));
        visited[i]=0;
        ans.pop_back();
    }

    return 0;
}