#include <iostream>
#include <queue>
using namespace std;

//다솜이가 기부할 수 있는 랜선의 길이 최대값 출력
//즉 N(50이하)개의 컴퓨터를 n-1개의 랜선으로 연결
//a-z : 1-26
//A-Z : 27-52
//0 : 연결하는 랜선 X

//기부할 수 있는 랜선의 길이 최댓값 출력
//모든 컴퓨가 연결되어 있지 않으면 -1 출력

#define MAX_VTXS 53
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
	//부모 찾기
	int findSets(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}

	//UnionSets (s1, s2 합치기)
	void UnionSets(int s1, int s2) {
		int root1 = findSets(s1);
		int root2 = findSets(s2);

		if (root1 != root2) {
			if (parent[root1] < parent[root2]) {
				parent[root1] += parent[root2];
				parent[root2] = root1;
			}
			else {
				parent[root2] += parent[root1];  //합쳐진 집합의 갯수 표현
				parent[root1] = root2;           //합쳐준다.
			}
			nSets--;
		}
	}
};

typedef struct Edge {
	int s, e, v;           //s: 시작노드, e: 끝노드, v: 가중치
	bool operator > (const Edge& temp) const {
		//현재 객체의 가중치가 더 크면 true를 반환하고, 그렇지 않으면 false를 반환합니다.
		return v > temp.v;
	}
}Edge;

int n;
char ch;

int main() {
	cin >> n;

	VertexSets vs(n);           //정점 갯수 n개 
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;      //mipHeap

	int sum = 0;         //랜선의 총합
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ch;
			int v= 0; //가중치
			if ('a' <= ch && ch <= 'z') v = ch - 'a' + 1;
			else if ('A' <= ch && ch <= 'Z') v = ch - 'A' + 27;
			sum += v;

			if (i != j && v != 0) {
				pq.push(Edge{ i,j,v});
			}
		}
	}


	int selectedEdges = 0;        //MST에 포함되는 edge 총 갯수, n-1까지 와야한다
	int result = 0;               //MST 가중치

	// 현재 우선순위 큐의 내용을 출력
	/*while (!pq.empty()) {
		Edge edge = pq.top();
		cout << "Edge: " << edge.s << " - " << edge.e << ", Weight: " << edge.v << endl;
		pq.pop();
	}*/

	while (!pq.empty()) {
		Edge now = pq.top();        //minHeap에서 가장 작은 엣지 꺼냄
		pq.pop();

		if (vs.findSets(now.s) != vs.findSets(now.e)) {  //사이클체크
			vs.UnionSets(now.s, now.e);                  //MST에 추가
			result += now.v;
			selectedEdges++;
		}
	}

	if (selectedEdges == n - 1) cout << sum - result;
	else cout << "-1";

	return 0;
}