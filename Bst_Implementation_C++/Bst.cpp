#include "Bst.h"

BstNode *BST :: _createNode(int data)
{
	BstNode *newNode = new BstNode;
	if (!newNode)
		return NULL;
	newNode->data = data;
	return newNode;
}

BstNode *BST :: _insert(int data, BstNode *root)
{
	BstNode *newNode = _createNode(data);
	if (!newNode)
		return NULL;

	if (root == NULL)
	{
		root = newNode;
		return root;
	}
	else if (data <= root->data)
		root->left = _insert(data, root->left);
	else
		root->right = _insert(data, root->right);
	return root;
}

bool BST :: _search(int data, BstNode *root)
{
	if (!root)
		return false;

	if (data == root->data)
		return true;
	else if (data < root->data)
		return _search(data, root->left);
	else
		return _search(data, root->right);
	return false;
}

bool BST :: insert(int data)
{
	_root = _insert(data, _root);
	if (_root)
		return true;
	return false;
}

bool BST :: search(int data)
{
	return _search(data, _root);
}


int main()
{
	BST bstree;

	bstree.insert(23);
	bstree.insert(12);
	bstree.insert(-2);
	bstree.insert(4);

	if (bstree.search(-2))
		std::cout << "Number is present in the tree\n";
	else
		std::cout << "Number is not present in the tree\n";

	return 0;
}