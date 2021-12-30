#include "Bst.h"

// Private/Utility Functions
BstNode *BST :: _create_Node_Util(int data)
{
	BstNode *newNode = new BstNode();
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode *BST :: _insert_Util(BstNode *root, int data)
{
	if (root == NULL) {
		root = _create_Node_Util(data);
	}
	else if (data <= root->data) {
		root->left = _insert_Util(root->left, data);
	}
	else {
		root->right = _insert_Util(root->right, data);
	}

	return root;
}

bool BST :: _search_Util(BstNode *root, int data)
{
	if (!root) {
		return false;
	}

	if (data == root->data) {
		return true;
	}
	else if (data < root->data) {
		return _search_Util(root->left, data);
	}
	else {
		return _search_Util(root->right, data);
	}

	return false;
}

BstNode *BST :: _delete_Util(BstNode *root, int data)
{
	if (_root == NULL)
		return NULL;
	else if (data < root->data)
		root->left = _delete_Util(root->left, data);
	else if (data > root->data)
		root->right = _delete_Util(root->right, data);
	else
	{
		// Case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// Case 2: 1 Child
		else if (root->left == NULL)
		{
			BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// Case 3: 2 Children
		else
		{
			BstNode *temp = _find_Min_Util(root->right);
			root->data = temp->data;
			root->right = _delete_Util(root->right, temp->data);
		}
	}
	return root;
}

BstNode* BST :: _find_Node_Util(int data)
{
	BstNode* temp = _root;
	while (temp != NULL)
	{
		if (data = temp->data)
			return temp;
		else if (data < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

int BST :: _find_Height_Util(BstNode *root)
{
	if (root == NULL)
		return -1;

	int height = _max_Util( _find_Height_Util(root->left), _find_Height_Util(root->right) ) + 1;
	return height;
}

BstNode* BST :: _find_Min_Util(BstNode *root)
{
	if (!root)
		return NULL;
	while (root->left != NULL)
		root = root->left;
	return root;
}

BstNode* BST :: _find_Max_Util(BstNode *root)
{
	if (!root)
		return NULL;
	while (root->right != NULL)
		root = root->right;
	return root;
}

int BST :: _max_Util(int a, int b)
{
	return (a > b ? a : b);
}

void BST :: _Preorder_Traversal(BstNode* root)
{
	if (root == NULL)
		return;

	std::cout << root->data << " ";
	_Preorder_Traversal(root->left);
	_Preorder_Traversal(root->right);
}

void BST :: _Inorder_Traversal(BstNode* root)
{
	if (root == NULL)
		return;

	_Inorder_Traversal(root->left);
	std::cout << root->data << " ";
	_Inorder_Traversal(root->right);
}

void BST :: _Postorder_Traversal(BstNode* root)
{
	if (root == NULL)
		return;
	
	_Postorder_Traversal(root->left);
	_Postorder_Traversal(root->right);
	std::cout << root->data << " ";
}

// Public Functions
bool BST :: insert(int data)
{
	BstNode* temp = _insert_Util(_root, data);
	if (temp) {
		_root = temp;
		return true;
	}
	return false;
}

bool BST :: search(int data)
{
	return _search_Util(_root, data);
}

bool BST :: remove(int data)
{
	BstNode* temp = _delete_Util(_root, data);
	if (temp) {
		_root = temp;
		return true;
	}
	return false;
}

int BST :: FindMin()
{
	BstNode* node = _find_Min_Util(_root);
	if (node)
		return node->data;
	return INT_MIN;
}

int BST :: FindMax()
{
	BstNode* node = _find_Max_Util(_root);
	if (node)
		return node->data;
	return INT_MIN;
}

int BST :: FindHeight()
{
	int height = _find_Height_Util(_root);
	if (height < 0)
		return INT_MIN;
	return height;
}

void BST :: Preorder_Traversal()
{
	_Preorder_Traversal(_root);
}

void BST :: Inorder_Traversal()
{
	_Inorder_Traversal(_root);
}

void BST :: Postorder_Traversal()
{
	_Postorder_Traversal(_root);
}

int BST :: InorderSuccessor(int data)
{
	BstNode *current = _find_Node_Util(data);
	if (current == NULL) return INT_MIN;
	// Case 1: Node has right subtree
	if (current->right != NULL)
	{
		return _find_Min_Util(current->right)->data;
	}
	// Case 2: Node has no right subtree
	else
	{
		BstNode *successor = NULL;
		BstNode *ancestor = _root;
		while (ancestor != current)
		{
			if (current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return ancestor->data;
	}
}

