#include <iostream>
#include <vector>
using namespace std;

class BinaryNode {
public:
	char data;
	BinaryNode* left;
	BinaryNode* right;

	//생성자, 소멸자
	BinaryNode(char val='0', BinaryNode* l = NULL, BinaryNode* r = NULL) :data(val), left(l), right(r) {}
	~BinaryNode(){}

	//set
	void setData(char n) { data = n; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	//get
	char getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

};

class BinaryTree {
public:
	BinaryNode* root;

	//생성자, 소멸자
	BinaryTree(){}
	~BinaryTree(){}

	//set
	void setRoot(BinaryNode* r) { root = r; }

	//get
	BinaryNode* getRoot() { return root; }

	//inorder
	void inorder(BinaryNode* n) {
		if (n != NULL) {
			if (n->getLeft() != NULL) { inorder(n->getLeft()); }
			cout << n->getData();
			if (n->getRight() != NULL) { inorder(n->getRight()); }
		}
	}
	//prreorder
	void preorder(BinaryNode* n) {
		if (n != NULL) {
			cout << n->getData();
			if (n->getLeft() != NULL) { preorder(n->getLeft()); }
			if (n->getRight() != NULL) { preorder(n->getRight()); }
		}
	}
	void postorder(BinaryNode* n) {
		if (n != NULL) {
			if (n->getLeft() != NULL) { postorder(n->getLeft()); }
			if (n->getRight() != NULL) { postorder(n->getRight()); }
			cout << n->getData();
		}
	}
};

int n;
BinaryTree tree;

int main() {

	cin >> n;
	vector<BinaryNode*> nodes(n);

	for (int i = 0; i < n; i++) {
		nodes[i] = new BinaryNode('A' + i);
	}

	//왼쪽 자식, 오른쪽 자식 연결
	for (int i = 0; i < n; i++) {
		char value, left_value, right_value;
		BinaryNode* leftData;
		BinaryNode* rightData;
		cin >> value >> left_value >> right_value;

		//루트 설정
		if (i == 0) {
			tree.setRoot(nodes[value - 'A']);
		}

		//자식 연결 - 왼쪽
		if (left_value != '.') {
			leftData = nodes[left_value - 'A'];
			nodes[value - 'A']->setLeft(leftData);
		}
		else {
			nodes[value - 'A']->setLeft(NULL);
		}

		//자식 연결 - 오른쪽
		if (right_value != '.') {
			rightData = nodes[right_value - 'A'];
			nodes[value - 'A']->setRight(rightData);
		}
		else {
			nodes[value - 'A']->setRight(NULL);
		}
	}

	tree.preorder(tree.getRoot());
	cout << "\n";
	tree.inorder(tree.getRoot());
	cout << "\n";
	tree.postorder(tree.getRoot());
}