#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//사람들 1,2,3.. (연속된 수)
//첫째 줄 : 사람 수
//둘째 줄 : 계산해야 하는 두 사람 번호
//셋째 줄 : 부모 자식 간 관계 수 m
//m 만큼  : 부모, 자식 번호 
//부모의 수는 한명
//친척 관계가 아닐 때 -1


int n, per1, per2, m, visited[103];
vector<vector<int>> family;
queue<int> q;

void bfs(int n) {
	//visited[n] = 1;
	q.push(n);

	while (q.size()) {
		int u = q.front(); q.pop();

		//인접 부분 돌기
		for (int i : family[u]) {
			if (!visited[i]) {
				visited[i] = visited[u] + 1;
				//cout << "현재 i는 " << i << " visited는" << visited[i] << "\n";
				q.push(i);
			}
		}
	}
}

int main() {

	cin >> n >> per1 >> per2 >> m;

	family.resize(n + 1);

	//family 인접 리스트 만들어 주기
	for (int i = 1; i <= m; i++) {
		int p, c;
		cin >> p >> c;
		family[p].push_back(c);
		family[c].push_back(p);
	}

	bfs(per1);

	if (visited[per2] == 0) cout << "-1";
	else cout << visited[per2];

	return 0;
}