#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, map[103][103], visited[103][103], y, x, ny, nx;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int sx, sy, ex, ey;
int zone, zoneS;
vector<int> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	zoneS++;

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n || map[ny][nx] == 0) continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {

	cin >> m >> n >> k;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 1;
		}
	}

	for (int a = 0; a < k; a++) {    //k 수만큼
		cin >> sx >> sy >> ex >> ey; 
		for (int i = m-ey; i < m-sy; i++) {               //y
			for (int j = sx; j < ex; j++) {           //x
				map[i][j] = 0;
			}
		}
	}

	//bfs or dfs 탐색
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				dfs(i, j);
				//넣어
				//cout << "zone의 넓이 : " << zoneS << "\n";
				v.push_back(zoneS);  //zone 넓이 구한거 넣어
				zoneS = 0;         //그리고 zone 넓이 초기화
				zone++;
			}
		}
	}

	sort(v.begin(), v.end());  //넓이 구한거 오름차순

	//cout << "zone의 수는  : " << zone << "\n";
	cout << zone << "\n";
	for (int i : v) {
		cout << i << " ";
	}
	return 0;
}