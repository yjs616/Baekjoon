#include <iostream>
#include <vector>
using namespace std;

//주어진 그래프가 트리인지 아닌지 판단하기
//1. 한노드에서 다른 모두의 노드로 이동 가능
//2. 엣지 사라지면 연결 안됨
//3. 노드 사이 엣지 추가 되면 주기가 발생함

//그래프가 트리인지 아닌지

//트리 : E = V-1

int T;  //전체 테스트 갯수
int n;  //그래프 노드 수
int m;  //그래프 엣지 수

vector<vector<int>> v;
vector<int> visited;


void dfs(int n){
    visited[n]=1;

    for(int i : v[n]){
        if(visited[i] == 0){
            dfs(i);
        }
    }

}


int main(){

    cin >> T;

    while(T > 0){
        cin >> n >> m;

        v.assign(n+1, vector<int>());
        visited.assign(n+1, 0);
        int isTree=1;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        if(m != n-1) cout << "graph" << "\n";   //E = V-1 안맞으면 "그래프"
        else{
            //E=V-1 맞으면 dfs로 단일 경로 나오는지 테스트
            //2.dfs
            dfs(1);

            //모두 다 방문했는지 확인
            for(int i=1; i <= n; i++){
                if(visited[i] == 0){
                    isTree = 0;
                    break;
                }
    
            }
            if(isTree) cout << "tree"<<"\n";
            else cout << "graph"<<"\n";

        }

        T--;
    }



    return 0;
}