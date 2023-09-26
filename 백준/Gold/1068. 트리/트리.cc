#include <iostream>
#include <vector>

using namespace std;

int n, cntLeaf, root;
vector<bool> visited;
vector<vector<int>> tree;
int deleteNode;

void DFS(int n) {
    visited[n] = true;
    bool isLeaf = true;

    for (int i : tree[n]) {
        if (!visited[i] && i != deleteNode) {
            isLeaf = false;
            DFS(i);
        }
    }

    if (isLeaf) {
        cntLeaf++;
    }
}

int main() {
    cin >> n;

    visited.resize(n, false);
    tree.resize(n);

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        if (node == -1) { // 루트
            root = i;
        }
        else {
            tree[node].push_back(i);
        }
    }

    cin >> deleteNode;

    if (deleteNode == root) {
        cout << "0" << "\n";
    }
    else {
        DFS(root);
        cout << cntLeaf << "\n";
    }

    return 0;
}
