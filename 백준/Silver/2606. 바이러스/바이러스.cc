#include <iostream>
#include <vector>
using namespace std;

//1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터 수
//컴퓨터 수 주어짐 (100이하)
//각 컴퓨터는 차례대로 번호 매겨짐
//직접 연결되어 있는 컴퓨터의 쌍 주어짐

//dfs로 접근 하기

int n, m, cnt, visited[103];
vector<vector<int>> adj;

void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
			cnt++;
		}
	}
}

int main() {

	cin >> n >> m;

	adj.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		
		adj[s].push_back(e);
		adj[e].push_back(s);

	}

	dfs(1);

	cout << cnt;

	return 0;
}