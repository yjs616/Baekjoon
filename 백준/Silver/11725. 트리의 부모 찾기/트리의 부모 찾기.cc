#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> parent(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    
    q.push(1); // Start from the root node

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (!parent[next]) { // If the parent of the next node is not set yet
                parent[next] = node; // Set the parent of the next node as current node
                q.push(next); // Add the next node to queue
            }
        }
    }

   for (int i = 2; i <= N; ++i) { 
       cout << parent[i] << "\n"; 
   }

   return 0;
}
