#include <iostream>
#include <string.h>
#include <tuple>
using namespace std;

int dist[1003][1003], n, m, s, e;
int visited[1003];
bool isfinish = false;

int dfs(int start) {
    if (start == e) {
        isfinish = true;
        return 0;
    }
    visited[start] = 1;

    for (int i = 1; i <= n; i++) {
        if (!isfinish) {
            if (!visited[i] && dist[start][i] != 0) {
                int distance = dist[start][i] + dfs(i);
                if (isfinish) {
                    return distance;
                }
            }
        }
    }

    return 0;
}

int main() {
    cin >> n >> m;

    memset(dist, 0, sizeof(dist));

    // 입력받기
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }

    for (int i = 0; i < m; i++) { // m은 테스트 갯수
        cin >> s >> e;
        int result = dfs(s);
        cout << result << "\n";

        isfinish = false;
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
