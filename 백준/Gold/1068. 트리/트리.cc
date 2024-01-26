#include <iostream>
#include <vector>
using namespace std;

int n, root, del, visited[53], cnt;
vector<int> v[53];

void dfs(int n){
    visited[n]= 1;
    bool isLeaf = true;     //가지마다 체크해야하니까

    for(int i : v[n]){
        if(!visited[i] && i != del){
            //방문하지 않았고 현재 i가 del이랑 다르면 dfs를 계속 호출해서 탐색해야 함
            isLeaf = false;
            dfs(i);
        }
    }

    if(isLeaf){
        cnt++;
    }

}

int main(){

    cin >> n;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        
        if(num == -1){
            root = i;
        }else{
            v[num].push_back(i);
        }
    }

    cin >> del;

    if(del == root){
        cout << 0 << "\n";
    }else{
        dfs(root);
        cout << cnt << "\n";
    }


    return 0;
}