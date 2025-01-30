#include <iostream>
#include <cstring>
using namespace std;

int t, n, arr[1003];
int visited[1003];

void dfs(int num){
    visited[num] = 1;
    /*for(int i : arr[num]){
        if(!visited[i]) dfs(i);
    }*/
    if(!visited[arr[num]]) dfs(arr[num]);
}

int main(){

    cin >> t;

    while(t--){
        cin >> n;  //순열 크기

        //초기화
        int cnt = 0;
        memset(visited, 0, sizeof(visited));

        for(int s=1; s<=n; s++){
            int e;
            cin >> e;
            arr[s] = e;
        }

        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
                //cout << "실행 " << "\n";
                cnt++;
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}