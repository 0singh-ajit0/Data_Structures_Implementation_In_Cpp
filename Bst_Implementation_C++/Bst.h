#include <iostream>
#include <limits>

struct BstNode
{
	int data;
	BstNode *left;
	BstNode *right;
};

class BST
{
private:
	// Variables
	BstNode *_root = NULL;

	// Functions
	BstNode *_create_Node_Util(int);
	BstNode *_insert_Util(BstNode *, int);
	bool _search_Util(BstNode *, int);
	BstNode *_delete_Util(BstNode *, int);
	BstNode* _find_Node_Util(int);
	int _find_Height_Util(BstNode *);
	BstNode* _find_Min_Util(BstNode *);
	BstNode* _find_Max_Util(BstNode *);
	int _max_Util(int, int);
	void _Preorder_Traversal(BstNode *);
	void _Inorder_Traversal(BstNode *);
	void _Postorder_Traversal(BstNode *);
public:
	bool insert(int);
	bool search(int);
	bool remove(int);
	int FindMin();
	int FindMax();
	int FindHeight();
	void Preorder_Traversal();
	void Inorder_Traversal();
	void Postorder_Traversal();
	int InorderSuccessor(int);
};
