// ---------------------------------------------- bintree.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 1/16/2023
// Date of Last Modification: 3/16/2023
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Definition file for a binary search tree class 
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//	- Implemented using NodeData object
//  - getHeight() can solve the height of any type of binary tree, not just a binary search tree
//  - findNodeRecursive() and retrieveRecursive() both find specific nodes of a tree
//		- findNodeRecursive() searches a general binary tree
//		- retrieveRecursive() searches a binary search tree
// 
// Assumptions:
// -Trees are built as binary search trees, except for arrayToBSTree() that builds a balanced binary tree
// -Nodes of a tree are linked together using pointers
// -Trees that are empty are equal
// -Height of a node at a leaf is 1
// -The height of a value not found is 0
// ---------------------------------------------------------------------------------------------------------------

#include "bintree.h"
#include "movie.h"

// ----------------------------Default constructor---------------------------------
// Creates an empty tree.
// Preconditions:NONE
// Postconditions: BinTree object with empty root node as data member.
// --------------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}


// --------------------------------Destructor--------------------------------------
// Destructor for class BinTree.
// Preconditions: A BinTree object has been previously created.
// Postconditions: Memory used for each NodeBST in BinTree is deallocated.
// --------------------------------------------------------------------------------
BinTree::~BinTree()
{
	removeHelper(root);
	root = NULL;
}

// -----------------------------------operator<<-----------------------------------
// Method to display the tree using inorder traversal helper.
// Preconditions: A BinTree object has been previously created.
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& curTree)
{
	// If tree is NOT empty, print out all nodes
	if (curTree.root != NULL) {
		// Traverse the tree in order and return ordered element through output
		curTree.inorderHelper(curTree.root, output);
	}
	// Else print out empty string
	output << "" << endl;
	return output;
}

// -----------------------------inorderHelper--------------------------------------
// Function to traverse the binary search tree inorder (left, visit, right).
// Preconditions: A BinTree object has been previously created.
// Postconditions: Variable of type ostream contains the order in which each 
// NodeData is going to be printed in console.
// --------------------------------------------------------------------------------
void BinTree::inorderHelper(NodeBST* curNode, ostream& output) const
{
	// If the tree is empty, return
	if (curNode == NULL) {
		return;
	}
	// Else traverse the tree and append current node item to output
	inorderHelper(curNode->left, output);
	output << *curNode->item << endl;
	inorderHelper(curNode->right, output);
}


// ----------------------------------Retrieve--------------------------------------
// Function to get the NodeData* of a given object in the tree (via pass-by-reference
// parameter) and to report whether the object is found(true or false).
// Preconditions: NodeData object to be found and BinTree object to be traversed have 
// been previously created. BinTree must be a binary search tree.
// Postconditions: The 2nd parameter NodeData may initially be garbage. If the object 
// is found, it will point to the actual object in the BinTree.
// --------------------------------------------------------------------------------
int BinTree::retrieve(const Movie& objToFind, Movie*& foundPtr)
{
	return retrieveRecursive(root, objToFind, foundPtr);
}

// -------------------------------retrieveRecursive--------------------------------
// Helper function for retrieve(). Uses recursion to find a given object in a binary 
// search tree.
// Preconditions: NodeData object to be found and BinTree object to be traversed have 
// been previously created. BinTree must be a binary search tree.
// Postconditions: The 3rd parameter NodeData may initially be garbage. If the object 
// is found, it will point to the actual object in the BinTree.
// --------------------------------------------------------------------------------
int BinTree::retrieveRecursive(NodeBST* curNode, const Movie& objToFind, Movie*& foundPtr)
{
	// If tree is empty
	if (curNode == NULL) {
		//return false;
		// If not found return -11
		return -1;
	}
	// If object is found then return 1 and set foundPtr to the node's pointer
	else if (objToFind == *curNode->item) {
		// If found and in stock, return 1
		if (curNode->item->getStock() > 0) {
			foundPtr = curNode->item;
			return 1;
		}
		// If found, but not in stock. Return 0 to search with another major actor
		foundPtr = curNode->item;
		return 0;
	}
	// If the object is smaller than the current node, move left
	else if (objToFind < *curNode->item) {
		return retrieveRecursive(curNode->left, objToFind, foundPtr);
	}
	// If the object is bigger than the current node, move right
	else {
		return retrieveRecursive(curNode->right, objToFind, foundPtr);
	}
}

	// ----------------------------------removeHelper----------------------------------
	// Helper method to empty a binary search tree using postorder traversal 
	// (left, right, visit).
	// Preconditions: BinTree object previously created.
	// Postconditions: BinTree is left empty.
	// --------------------------------------------------------------------------------
	void BinTree::removeHelper(NodeBST * toRemove)
	{
		// If the tree is NOT empty remove nodes starting from the leaves to the root
		if (toRemove != NULL) {
			removeHelper(toRemove->left);
			removeHelper(toRemove->right);
			delete toRemove->item;
			toRemove->item = NULL;
			delete toRemove;
			toRemove = NULL;
		}
		// If the tree is empty do nothing
	}

	// ------------------------------Insert--------------------------------------------
	// Function to insert a new node in the tree. Uses insertRecursive private funtion.
	// Preconditions: Movie* previously created to be inserted in BinTree.
	// Postconditions: BinTree has a new NodeBST.
	// --------------------------------------------------------------------------------
	bool BinTree::insert(Movie * &newData)
	{
		//return true;
		return insertRecursive(root, newData);
	}

	//--------------------------insertRecursive---------------------------------------
	//Recursive function to insert a new node in the tree.
	//Preconditions: NodeData* previously created to be inserted in BinTree.
	//Postconditions: BinTree has a new NodeBST.
	//--------------------------------------------------------------------------------
	bool BinTree::insertRecursive(NodeBST * &curNode, Movie * &newData)
	{
		// If newData is NULL stop there
		if (newData == NULL) {
			return false;
		}
		// If an empty node is found insert at current root node
		if (curNode == NULL) {
			curNode = new NodeBST;
			curNode->item = newData;
			curNode->left = NULL;
			curNode->right = NULL;
			return true;
		}

		// How to compare two same movies with different major actors for classics?

		// Check for duplicates
		else if (*newData == *curNode->item) {
			//// If same movie, add both objecst into one
			//curNode->item->setStock(newData->getStock() + curNode->item->getStock()); // Add both stocks
			//delete newData;
			//newData = nullptr;
			//
			return false;
		}
		// If item to be inserted is less than current node then go left
		else if (*curNode->item > *newData) {
			return insertRecursive(curNode->left, newData);
		}
		// If item to be inserted is greater than current node then go right
		else {
			return insertRecursive(curNode->right, newData);
		}
	}
