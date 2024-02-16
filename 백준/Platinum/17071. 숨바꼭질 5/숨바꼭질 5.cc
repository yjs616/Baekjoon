#include <iostream>
#include <queue>
using namespace std;

int const MAX = 500000;
int n, k, visited[2][MAX+3], sec=1;
bool ok = false;

int main(){

    cin >> n >> k;

    if(n==k){
        cout << 0 << "\n";
        return 0;
    }

    //bfs
    queue<int> q;
    q.push(n);
    visited[0][n]=1;

    while(q.size()){
        k += sec;

        if(k> MAX) break;
        //홀홀, 짝짝 맞으면
        if(visited[sec%2][k]){
            ok = true;
            break;
        }

        //층층으로
        int qSize = q.size();
        for(int i=0; i< qSize; i++){
            int x = q.front(); q.pop();
            for(int nx  : {x-1, x+1, 2*x}){
                if(nx <0 || nx> MAX) continue;
                if(!visited[sec%2][nx]){
                    visited[sec%2][nx] = visited[(sec+1)%2][x]+1;

                    if(nx == k){
                        ok = true;
                        break;
                    }
                    q.push(nx);
                }

            }
            if(ok) break;
            
        }
        if(ok) break;
        else sec++;
        
    }

    if(ok) cout << sec << "\n";
    else cout << -1 << "\n";

    return 0;
}
