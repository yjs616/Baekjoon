#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[503];
bool visited[503];
bool isTree;

void dfs(int cur, int parent) {
    visited[cur] = true;

    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next, cur);
        } else{
            if(next != parent){
                isTree = false;
                return;
            }
        }
    }
}

int main() {
    int caseCnt = 1;

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        // 초기화
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        isTree = true;

        // 그래프 입력 받기
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int treeCnt = 0;

        //모든 정점 dfs
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
                if (isTree) {
                    treeCnt++;
                }
                isTree = true;
            }
        }

        // 결과 
        cout << "Case " << caseCnt << ": ";
        if (treeCnt == 0) {
            cout << "No trees." << "\n";
        } else if (treeCnt == 1) {
            cout << "There is one tree." << "\n";
        } else {
            cout << "A forest of " << treeCnt << " trees." << "\n";
        }

        caseCnt++;
    }

    return 0;
}