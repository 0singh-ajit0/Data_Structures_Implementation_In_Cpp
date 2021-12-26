#include "Bst.h"

BstNode *BST :: _createNode(int data)
{
	BstNode *newNode = new BstNode();
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode *BST :: _insert(BstNode *root, int data)
{
	if (root == NULL) {
		root = _createNode(data);
	}
	else if (data <= root->data) {
		root->left = _insert(root->left, data);
	}
	else {
		root->right = _insert(root->right, data);
	}

	return root;
}

bool BST :: _search(BstNode *root, int data)
{
	if (!root) {
		return false;
	}

	if (data == root->data) {
		return true;
	}
	else if (data < root->data) {
		return _search(root->left, data);
	}
	else {
		return _search(root->right, data);
	}

	return false;
}

bool BST :: insert(int data)
{
	_root = _insert(_root, data);
	if (_root)
		return true;

	return false;
}

bool BST :: search(int data)
{
	return _search(_root, data);
}

BstNode *BST :: returnRoot()
{
	return _root;
}

