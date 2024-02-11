#include <iostream>
#include <queue>
using namespace std;

int n, k, visited[200003];

void bfs(int n){
    visited[n]=1;

    queue<int> q;
    q.push(n);

    while(q.size()){
        int cur = q.front(); q.pop();

        for(int nx : {cur-1, cur+1, 2*cur}){
            if(nx < 0 || nx > 100000) continue;

            if(!visited[nx]){
                visited[nx] = visited[cur] +1;
                q.push(nx);
            }
        }

    }
}

int main(){

    cin >> n >> k;

    bfs(n);      //수빈이 위치에서 시작

    cout << visited[k]-1 << "\n";   //동생 위치 최단 거리 -1 = 최단 시각

    
    return 0;
}