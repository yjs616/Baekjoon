#include <iostream>
#include <vector>
using namespace std;

int t, visited[1003];
int adj[1003];

void dfs(int u) {
	visited[u] = 1;
	if (visited[adj[u]] == 0) {
		dfs(adj[u]);	
	}	
}

int main() {

	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		//vertext 연결
		for (int j = 1; j <= n; j++) { 
			cin >> adj[j];
		}

		//cycle과 visited 초기화
		int cycle = 0;
		for (int j = 1; j <= n; j++) {
			visited[j] = false;
		}

		for (int k = 1; k <= n; k++) {
			if (visited[k] == 0) {
				dfs(k);
				cycle++;    //재귀 끝나면 cycle++
			}
		}	

		cout << cycle << "\n";

	}

	return 0;
}