#include <iostream>
#include <vector>
using namespace std;

int n, m, visited[1003], cnt;
vector<vector<int>> adj(1003);

void dfs(int n){
    visited[n]=1;

    for(int i : adj[n]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }

    cout  << cnt << "\n";

    return 0;
}