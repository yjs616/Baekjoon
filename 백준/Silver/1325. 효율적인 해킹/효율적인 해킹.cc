#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
using namespace std;

int n, m, visited[10003], cnt;
vector<int> v[10003];

void dfs(int n){
    visited[n]=1;

    for(int i : v[n]){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
}

int main(){

    cin >> n >> m;


    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }

    int max=0;
    vector<int> ret(n+1);

    for(int i=1; i<=n; i++){
        dfs(i);

        if(max < cnt){
            max = cnt;
        }
        ret[i]= cnt;

        //visited, cnt 초기화하기
        memset(visited, 0, sizeof(visited));
        cnt=0;

    }

    for(int i=1; i<=n; i++){
        if(ret[i]==max) cout << i << " ";
    }

    return 0;
}