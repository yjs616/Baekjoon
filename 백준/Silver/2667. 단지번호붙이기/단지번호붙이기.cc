#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

//위아래 혹은 좌우 
//대각선 X
//1. 단지 수 출력
//2. 각 단지에 속하는 집의 수 출력
//방향맵을 이용한 bfs??

int n, visited[27][27], danji_cnt, house_cnt, y, x, ny, nx;
char c[27][27];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0, 1, 0, -1 };

vector<int> house;


int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == '1' && !visited[i][j]) {
				visited[i][j] = 1;
				q.push({ i, j });
				house_cnt=1;
				while (q.size()) {
					tie(y, x) = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						ny = y + dy[k];
						nx = x + dx[k];

						if (ny < 0 || ny >= n || nx < 0 || nx >= n || c[ny][nx] == '0') continue;
						//1인데 방문함
						if (visited[ny][nx]) continue;

						visited[ny][nx] = 1;    

						q.push({ ny, nx });
						house_cnt++;
					}
				}
				house.push_back(house_cnt);
			}
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << "\n";

	for (int k : house) {
		cout << k << "\n";
	}


	return 0;
}