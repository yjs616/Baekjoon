#include <iostream>
#include <queue>
using namespace std;

int n, k, nx;
int dx[]={-1, 1, 2};
int visited[200003];
int caseCnt[200003];     

void bfs(int s){
    visited[s] = 1;
    caseCnt[s]=1;

    queue<int> q;
    q.push(s);

    while(q.size()){
        int cur = q.front(); q.pop();

        for(int i=0; i<3; i++){
            if(i==2){
                nx = cur*dx[i];
            }else{
                nx = cur + dx[i];
            }

            if(nx<0 || nx>100000) continue;
            if(!visited[nx]){
                visited[nx] = visited[cur] + 1;
                q.push(nx);
                caseCnt[nx] += caseCnt[cur]; 
            }else{
                if(visited[nx] == visited[cur] +1){
                    caseCnt[nx]+= caseCnt[cur];
                }
            }
        }
    }
}

int main(){

    cin >> n >> k;

    bfs(n);

    cout << visited[k]-1 << "\n";     //최단 시간(횟수)
    cout << caseCnt[k] << "\n";       //경우의 수

    return 0;
}