#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//방문할 수 있는 정점이 여러개인 경우 작은 것부터
//정점번호는 1부터 n까지
int N, M, V, visited[1003];
vector<vector<int>> adj(1003);

void dfs(int n) {
	visited[n] = 1;
	cout << n << " ";
	for (int u : adj[n]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
	
}

void bfs(int n) {
	queue<int> q;
	visited[n] = 1;
	q.push(n);
	cout << n << " ";
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!visited[v]) {
				visited[v] = visited[u] + 1;
				cout << v << " ";
				q.push(v);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// adj 배열의 각 리스트를 오름차순 정렬
	for(int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	
	dfs(V);
	cout << "\n";

	//visited 초기화
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}

	bfs(V);

	/*for(int i=1;i<=N;i++){
		for(int j : adj[i]){
			cout<<i<<":"<<j<<"\n";
		}
	}*/

	return 0;
}