#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
int s, e;
vector<vector<int>> v;
int visited[300003];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : v[current]) {
            if (visited[next] == -1) {  // 아직 방문하지 않은 도시만 탐색
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k >> x;

    v.resize(n + 1);
    fill(visited, visited + n + 1, -1);

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        v[s].push_back(e);
    }

    bfs(x);

    bool isPos = false;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == k) {
            cout << i << "\n";
            isPos = true;
        }
    }

    if (!isPos) {
        cout << -1;
    }

    return 0;
}
