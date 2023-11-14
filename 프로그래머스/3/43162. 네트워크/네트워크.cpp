#include <iostream>
#include <vector>

using namespace std;

class VertexSets {
public:
    int parent[203];
    int nSets;

    VertexSets(int n) : nSets(n) {
        for (int i = 0; i < nSets; i++)
            parent[i] = -1;
    }

    bool isRoot(int i) {
        return parent[i] < 0;
    }

    int findSet(int v) {
        while (!isRoot(v)) {
            v = parent[v];
        }
        return v;
    }

    void unionSets(int s1, int s2) {
        int root1 = findSet(s1);
        int root2 = findSet(s2);

        if (root1 != root2) {
            if (parent[root1] < parent[root2]) {
                parent[root1] += parent[root2];
                parent[root2] = root1;
            } else {
                parent[root2] += parent[root1];
                parent[root1] = root2;
            }

            nSets--;
        }
    }
};

int solution(int n, vector<vector<int>> computers) {
    VertexSets v(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && i <= j) {
                v.unionSets(i, j);
            }
        }
    }

    return v.nSets;
}

