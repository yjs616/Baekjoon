#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int map[103][103],visited[103][103], n, y, x, ny, nx;
int height=1, maxH=1, maxSafe=1;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x) {

	visited[y][x] = 1;
	queue<pair<int, int>> q;

	q.push({ y, x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] <= height) continue;
			if (!visited[ny][nx]) {
				//cout << "안전지대 ny,nx는 - ny :  " << ny << " nx : " << nx << "\n";
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maxH < map[i][j]) maxH = map[i][j];         //높이 N 최댓값 찾기
		}
	}

	while(height<= maxH){

		int cnt = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > height && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		height++;              //height maxH까지 하나씩 증가

		if (cnt > maxSafe) maxSafe = cnt;	

	}

	cout << maxSafe;

	return 0;
}