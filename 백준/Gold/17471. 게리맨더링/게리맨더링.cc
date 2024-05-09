#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
const int INF = 987654321;
int n;

vector<int> adj[11];    //2차 배열
int people[11], comp[11], visited[11];
int ret = INF;

pair<int, int> dfs(int here, int value){
    visited[here]=1;
    pair<int, int> ret= {1, people[here]};
    for(int there : adj[here]){
        if(visited[there]) continue;
        if(comp[there] != value) continue;
        pair<int, int> temp = dfs(there, value);
        ret.first += temp.first;
        ret.second += temp.second;
    }

    return ret;

}

int main(){
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> people[i];
    }

    for(int i=1; i<=n; i++){
        int b, c;
        cin >> b;
        for(int j=0; j<b; j++){
            cin >> c;
            adj[i].push_back(c);
        }
    }

    //지역을 선거구 색을 색칠한다 (분리한다)
    for(int i=1; i < (1<<n)-1; i++){
        //visited와 comp 초기화 (각 경우에 대한 관찰이니까)
        fill(visited, visited+11, 0);
        fill(comp, comp+11, 0);
        int idx1=-1; int idx2=-1;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){//1로 색칠된 경우
                comp[j+1]=1;
                idx1= j+1;
            }else{ //0으로 색칠된 경우
                idx2 = j+1;
            }
        }

        //분리 다했으니까 분리된 그룹끼리 dfs돌리기
        pair<int, int> dfs1 = dfs(idx1, 1);
        pair<int, int> dfs0 = dfs(idx2, 0);

        //선거구 2개로 잘 나눠졌으면 인구수의 합의 최솟값 갱신
        if(dfs1.first + dfs0.first == n){
            ret = min(ret, abs(dfs1.second - dfs0.second));
        }
    }

    cout << ((ret==INF)? -1 : ret) << "\n";

    return 0;
}