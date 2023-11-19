#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//남초 대학교와 여초 대학교들을 연결(여-여, 남-남 연결 불가)
//모든 대학교로 이동 가능
//최단거리

//학교 갯수, 도로 갯수
//남초M, 여초W

#define MAX_VTXS 1003
class VertexSets {
public:
	int parent[MAX_VTXS];
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

	//Find
	int FindSets(int v) {
		while (!isRoot(v)) v = parent[v];
		//계속 돌다가
		return v;
	}

	//UnionSets
	void UnionSets(int s1, int s2) {
		int root1 = FindSets(s1);
		int root2 = FindSets(s2);

		if (root1 != root2) {
			if (parent[root1] < parent[root2]) {
				parent[root1] += parent[root2];
				parent[root2] = root1;
			}
			else {
				parent[root2] += parent[root1];
				parent[root1] = root2;
			}
		}
	}

};

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
}Edge;
int n, m;
int s, e, v;

int main() {
	cin >> n >> m;       //n-학교수 m-도로수

	//객체
	VertexSets vs(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	vector<char> gender(n+1);

	//대학 여초? 남초?
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;	
		gender[i] = c;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> v;
		pq.push(Edge{s,e,v});
	}

	/*while (!pq.empty()) {
		Edge edge = pq.top();
		cout << "Edge: " << edge.s << " - " << edge.e << ", Weight: " << edge.v << endl;
		pq.pop();
	}*/

	int selectedEdge = 0;     //엣지 갯수
	int result = 0;            //mst 가중치

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (gender[now.s] != gender[now.e]) {                   //남남 여여 체크
			if (vs.FindSets(now.s) != vs.FindSets(now.e)) {     //사이클 체크
				//결합
				vs.UnionSets(now.s, now.e);
				result += now.v;         //mst 가중치 추가
				selectedEdge++;          //연결된 엣지 수 증가
			}
		}
	}

	if (selectedEdge == n - 1) cout << result;
	else cout << "-1";

	return 0;
}