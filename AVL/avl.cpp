#include<iostream>
#include<map>
#include<string>
using namespace std;

template<typename K, typename V>
struct AVLTreeNode {
	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr),
		_right(nullptr),
		_kv(kv),
		h(1)
	{};
	AVLTreeNode<K, V> _left;
	AVLTreeNode<K, V> _right;
	pair<K, V> _kv;
	int h;
};

AVLTreeNode<int, int>* rightRotate(AVLTreeNode<int, int>* node) {
	AVLTreeNode<int, int> * rotateCenterNode = node->_left;
	node->_left = rotateCenterNode->_right;
	rotateCenterNode->_right = node;
	node->h = max(node->_left != nullptr ? node->_left->h : 0, node->_right != nullptr ? node->_right->h : 0) + 1;
	rotateCenterNode->h = max(rotateCenterNode->_left != nullptr ? rotateCenterNode->_left->h : 0, rotateCenterNode->_right != nullptr ? rotateCenterNode->_right->h : 0) + 1;
	return rotateCenterNode;
}
AVLTreeNode<int, int>* leftRotate(AVLTreeNode<int, int>* node) {
	AVLTreeNode<int, int>* rotateCenterNode = node->_right;
	node->_right = rotateCenterNode->_left;
	rotateCenterNode->_left = node;
	node->h = max(node->_left != nullptr ? node->_left->h : 0, node->_right != nullptr ? node->_right->h : 0) + 1;
	rotateCenterNode->h = max(rotateCenterNode->_left != nullptr ? rotateCenterNode->_left->h : 0, rotateCenterNode->_right != nullptr ? rotateCenterNode->_right->h : 0) + 1;
	return rotateCenterNode;
}

void insertNode(AVLTreeNode<int, int>* tree, AVLTreeNode<int, int>* node) {
	if (tree == nullptr) {
		tree = node;
		return;
	}
	struct pathNode {
		AVLTreeNode<int, int>* node;
		pathNode* next;
	};
	pathNode* tail = new pathNode();
	tail->next = nullptr;
	tail->node = tree;
	AVLTreeNode<int, int>* cur = tree;
	while (1) {
		if (cur->_kv.first >= node->_kv.first && cur->_left == nullptr) {
			cur->_left = 
		}
	}
}