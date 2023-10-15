#include <iostream>
#include <vector>

using namespace std;

class BinaryNode {
public:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	//생성, 소멸
	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r= NULL):data(val),left(l),right(r){}
	~BinaryNode(){}

	//set
	void setData(int n) { data = n; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	//get
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

};

class BinaryTree {
public:
	BinaryNode* root;

	//생성, 소멸
	BinaryTree(){}
	~BinaryTree(){}

	//set
	void setRoot(BinaryNode* r) { root = r; }

	//get
	BinaryNode* getRoot() { return root; }

	//makeTree(insert)
	void makeTree(BinaryNode* r, BinaryNode* n) {
		if (r->getData() == n->getData()) return;
		else if (r->getData() > n->getData()) {
			if (r->getLeft() == NULL) {
				r->setLeft(n);
			}
			else {
				makeTree(r->getLeft(), n);
			}
		}
		else {
			if (r->getRight() == NULL) {
				r->setRight(n);
			}
			else {
				makeTree(r->getRight(), n);
			}
		}
	}

	//왼 -> 오 -> 루트
	void postorder(BinaryNode* r) {
		if (r->getLeft() != NULL) { postorder(r->getLeft());}
		if (r->getRight() != NULL) { postorder(r->getRight()); }
		cout << r->getData() << "\n";
	}
};

vector<BinaryNode*> nodes;
BinaryTree tree;
int num;

int main() {


	while(cin>> num){
		
		BinaryNode* node = new BinaryNode(num);
		nodes.push_back(node);

		if (nodes.size() == 1) {
			tree.setRoot(node);
		}
		else {
			tree.makeTree(tree.getRoot(), node);
		}
	}

	tree.postorder(tree.getRoot());


	return 0;
}