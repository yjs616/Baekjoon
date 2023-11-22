#include <iostream>
#include <vector>

using namespace std;
#define MAX 999                 

int n, m;


int main() {
	cin >> n;

	vector<vector<int>> dist(n);   //인접행렬

	int num;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> num;

			if (num == 1) {
				dist[i].push_back(num);
			}
			else {
				dist[i].push_back(MAX);
			}
		}
	}

	//shorest path
	for (int k = 0; k < n; k++) {
		for (int i = 0; i <n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == MAX) cout << "0" << " ";
			else cout << "1" <<" ";
		}
		cout << "\n";
	}


	return 0;
}
