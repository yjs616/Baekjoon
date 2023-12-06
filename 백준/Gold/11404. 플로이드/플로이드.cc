#include <iostream>
using namespace std;

int n, m, s, e, v, cost[103][103], INF=987654321;

int main() {

	cin >> n >> m;

	//cost초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cost[i][j] = INF;
		}
	}

	//비용 업데이트
	for (int i = 1; i <= m; i++) {
		cin >> s >> e >> v;
		if (cost[s][e] != INF)
			cost[s][e] = min(cost[s][e], v);
		else
			cost[s][e] = v;
	}

	//floyd SP
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
			}
		}
	}

	//최소비용 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF)
				cout << 0 << " ";
			else
				cout << cost[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}