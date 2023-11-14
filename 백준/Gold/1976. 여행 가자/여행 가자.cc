#include <iostream>
using namespace std;

//1,2,3은 루트가 같아야 한다
int n, m;
#define MAX_VTXS 203

class VertextSets {
	int parent[MAX_VTXS];
	int nSets;

public:
	VertextSets(int n) : nSets(n) {
		for (int i = 0; i <= nSets; i++) {
			parent[i] = -1;
		}
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSets(int v) {
		while (!isRoot(v)) v = parent[v];
		return v;
	}
	void unionSets(int s1, int s2) {
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

int main() {
	cin >> n >> m;

	VertextSets v(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j<= n; j++) {
			int num;
			cin >> num;

			if (num == 1 && i <= j) v.unionSets(i, j);
		}
	}
	int std;
	bool isPossible = true;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		if (i == 0) std = v.findSets(x);
		else {
			if (v.findSets(std) != v.findSets(x)) {
				isPossible = false;
				break;
			}
		}
	}

	if (isPossible) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}
