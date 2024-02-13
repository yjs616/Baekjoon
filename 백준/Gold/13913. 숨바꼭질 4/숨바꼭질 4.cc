#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, visited[200003], pre[100003];
vector<int> ans;

void bfs(int n){
    visited[n]=1;

    queue<int> q;
    q.push(n);

    while(q.size()){
        int now = q.front(); q.pop();

        for(int next : {now-1, now+1, 2*now}){
            if(next <0 || next>100000) continue;
            if(!visited[next]){
                visited[next] = visited[now]+1;
                q.push(next);
                //연쇄걸기
                pre[next] = now;
            }
        }
    }
}

int main(){

    cin >> n >> k;

    bfs(n);

    cout << visited[k]-1 << "\n";

    for(int i=k; i != n; i=pre[i]){
        ans.push_back(i);
    }
    ans.push_back(n);

    reverse(ans.begin(), ans.end());

    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}