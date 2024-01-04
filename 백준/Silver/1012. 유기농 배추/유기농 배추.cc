#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int field[53][53], visited[53][53], y, x, ny, nx;
int t, m, n, k;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	visited[y][x] = 1;

	queue<pair<int, int>> q;

	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny<0 || ny>=n || nx<0 || nx>=m || field[ny][nx] == 0) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}	
	}
}

int main() {

	cin >> t;

	for (int i = 0; i < t; i++) {

		int cnt=0;

		cin >> m >> n >> k;        //m:가로길이, n:세로길이

		for (int i = 0; i < n; i++) {         //배열 리셋
			for (int j = 0; j < m; j++) {
				field[i][j] = 0;
				visited[i][j] = 0;
			}
		}
 
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			field[y][x] = 1;
		}


		for (int i = 0; i < n; i++) { //y
			for (int j = 0; j < m; j++) { //x
				if (field[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j);
					cnt++;
				}
			}

		}

		cout << cnt << "\n";
	}

	
	return 0;
}