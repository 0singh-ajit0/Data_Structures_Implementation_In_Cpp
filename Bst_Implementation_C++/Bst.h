#include <iostream>

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
	BstNode *_createNode(int);
	BstNode *_insert(int, BstNode *);
	bool _search(int, BstNode *);
public:
	bool insert(int);
	bool search(int);
};