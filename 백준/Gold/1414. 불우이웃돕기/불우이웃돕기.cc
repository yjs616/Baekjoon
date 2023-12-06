#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class VertexSets {
public:
	int parent[53];
	int nSets;

	//생성자
	VertexSets(int n) :nSets(n) {
		for (int i = 0; i <= nSets; i++) {
			parent[i] = -1;
		}
	}

	//isRoot
	bool isRoot(int i) {
		return parent[i] < 0;
	}

	//find
	int findSets(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	//Union
	void UnionSets(int s1, int s2) {
		int root1 = findSets(s1);
		int root2 = findSets(s2);

		if (root1 != root2) {
			if (parent[root1] < parent[root2]) {
				parent[root1] += parent[root2];
				parent[root2] = root1;
			}
			else {
				parent[root2] += parent[root1];
				parent[root1] = root2;
			}
			nSets--;
		}
	}
};

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}

}Edge;

int N;
char c;

int main() {

	cin >> N;

	VertexSets vs(N);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	int sum = 0;        //랜선의 총합
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			int v = 0;             //문자->가중치
			if ('a' <= c && c <= 'z') v = c - 'a' + 1;
			else if ('A' <= c && c <= 'Z') v = c - 'A' + 27;

			//랜선 총합 구하기
			sum += v;

			if (i != j && v != 0) {
				pq.push(Edge{ i,j,v });
			}
		}
	}

	//MST
	int selectEdges = 0;        //MST에 포함되는 엣지 갯수
	int result = 0;             //MST 가중치

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (vs.findSets(now.s) != vs.findSets(now.e)) { //사이클 체크
			vs.UnionSets(now.s, now.e);
			result += now.v;                            //mst 가중치 증가
			selectEdges++;
		}
	}

	if (selectEdges == N - 1) cout << sum - result;
	else cout << -1;

	return 0;
}