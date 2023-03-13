// ---------------------------------------------- bintree.cpp ----------------------------------------------------
// Kelly M. Kauffman			CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 1/16/2023
// Date of Last Modification: 1/25/2023
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

//// ------------------------------Copy constructor----------------------------------
//// Makes a deep copy of the right hand side binary tree into the left hand side 
//// binary tree.
//// Preconditions: BinTree object to be copied has been previously created.
//// Postconditions: BinTree object that is identical in elements and structure to 
//// the right hand side BinTree, but with different memory address.
//// --------------------------------------------------------------------------------
//BinTree::BinTree(const BinTree& rhs)
//{
//	root = copy(rhs.root);
//}

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
//
//// --------------------------------operator=---------------------------------------
//// Overloaded assignment operator. Makes a deep copy of right hand side BST.
//// Uses removeHelper(bstNode *) to empty the tree and copy(const bstNode *) to copy
//// all nodes of the rhs tree.
//// Preconditions: A BinTree object has been previously created.
//// Postconditions: A BinTree object that is identical in elements and structure to 
//// the right hand side BinTree, but with different memory address.
//// --------------------------------------------------------------------------------
//const BinTree& BinTree::operator=(const BinTree& rhs)
//{
//	// If left hand side BinTree is NOT empty
//	if (!isEmpty()) {
//		if (*this == rhs) {	// If lhs bst == rhs bst return lhs as is	
//			return *this;												
//		}
//		removeHelper(root);	// Else empty the tree
//	}
//	root = copy(rhs.root);
//	return *this;
//}
//
//// --------------------------------------copy--------------------------------------
//// Helper method to copy a binary search tree using preorder traversal 
//// (visit, left, right).
//// Preconditions: Root of the BinTree that will be copied.
//// Postconditions: All the NodeBSTs of one BinTree have been copied to
//// to the new NodeBSTs of another BinTree.
//// --------------------------------------------------------------------------------
//NodeBST* BinTree::copy(const NodeBST* toCopy)
//{
//	// If the tree to be copied is empty, return NULL
//	if (toCopy == NULL) {
//		return NULL;
//	}
//	// Else crete a new bstNode to copy current node
//	NodeBST* copyNode = new NodeBST;
//	// Traverse the tree to copy all the nodes
//	copyNode->item = new NodeData (*toCopy->item);
//	copyNode->left = copy(toCopy->left);
//	copyNode->right = copy(toCopy->right);
//	return copyNode;
//}

// -----------------------------Operator ==----------------------------------------
// Overload of operator==.
// Define two trees to be equal if they have the same data and same structure.
// Preconditions: Two BinTree objects have been previously created to be compared.
// Postconditions: BinTrees remains unchanged.
// --------------------------------------------------------------------------------
////////bool BinTree::operator==(const BinTree& rhs) const
////////{
////////	// If both trees are empty, they are the same
////////	if (this->root == NULL && rhs.root == NULL) {
////////		return true;
////////	} 
////////	// If only one tree is empty and the other one not or the first node item is 
////////	// different they are not the same
////////	else if ((this->root == NULL && rhs.root != NULL) || (this->root != NULL && rhs.root == NULL)) {
////////		return false;
////////	}
////////	// Else if neither is empty and the first nodes are not the same, return false
////////	else if ((this->root != NULL && rhs.root != NULL) && (*(this->root->item) != *(rhs.root->item))) {
////////		return false;
////////	}
////////	// Else if neither is empty and both first bstNode item's are the same, find if
////////	// all the tree items and structure are the same
////////	else if ((this->root != NULL && rhs.root != NULL) && (*(this->root->item) == *(rhs.root->item))) {
////////		return compare(this->root, rhs.root);
////////	}
////////	// Catch any oddities/errors
////////	else {
////////		cout << "There was a problem with testing equality" << endl;
////////		return false;
////////	}
////////}

////////// ---------------------------Compare----------------------------------------------
////////// Helper function for operator == and operator !=().
////////// Preconditions: Both NodeBST objects have been previously created or set to NULL
////////// to be compared.
////////// Postconditions: If all NodeBST have the same data and follow the same path 
////////// return true, else return false.
////////// --------------------------------------------------------------------------------
////////bool BinTree::compare(NodeBST* left, NodeBST* right) const
////////{
////////	// If the first node of each subtree is empty they are the same
////////	if (left == NULL && right == NULL) {
////////		return true;
////////	} 
////////	// If one subtree is empty and the other one not return false
////////	else if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
////////		return false;
////////	}
////////	// If left and right items are the same, keep searching tree
////////	else if (*left->item == *right->item) {
////////		bool b1 = compare(left->left, right->left);
////////		bool b2 = compare(left->right, right->right);
////////		return b1 && b2;
////////	}
////////	// If left and right items are different
////////	return false;
////////}

//////////// --------------------------Operator !=-------------------------------------------
//////////// Overload of operator!=
//////////// Determine if two binary treeas are not equal.
//////////// Preconditions: Two BinTree objects have been previously created to be compared.
//////////// Postconditions: BinTrees remains unchanged.
//////////// --------------------------------------------------------------------------------
//////////bool BinTree::operator!=(const BinTree& rhs) const
//////////{
//////////	return !(*this == rhs);
//////////}

// ----------------------------------Retrieve--------------------------------------
// Function to get the NodeData* of a given object in the tree (via pass-by-reference
// parameter) and to report whether the object is found(true or false).
// Preconditions: NodeData object to be found and BinTree object to be traversed have 
// been previously created. BinTree must be a binary search tree.
// Postconditions: The 2nd parameter NodeData may initially be garbage. If the object 
// is found, it will point to the actual object in the BinTree.
// --------------------------------------------------------------------------------
bool BinTree::retrieve(const Movie& objToFind, Movie*& foundPtr)
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
bool BinTree::retrieveRecursive(NodeBST* curNode, const Movie& objToFind, Movie*& foundPtr)
{
	// If tree is empty
	if (curNode == NULL) {
		return false;
	}
	// If object is found then return and set foundPtr to the node's pointer
	else if (objToFind == *curNode->item) {
		foundPtr = curNode->item;
		return true;
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

//// -------------------------------getHeight----------------------------------------
//// Function to find the height of a given value in the tree. Uses findNodeRecursive()
//// and getHeightRecursive() private helper functions.
//// Preconditions: NodeData object to be found and BinTree object to be traversed have 
//// been previously created. BinTree is considered as a general binary tree.The height 
//// of a node at a leaf is 1,height of a node at the next level is 2, and so on.
//// If not found is 0.
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//int BinTree::getHeight(const NodeData& toFind) const
//{
//	// Recursively find the node of the tree that contains the value to find
//	return findNodeRecursive(toFind, root);
//}
//
//// ---------------------------findNodeRecursive------------------------------------
//// Helper function to find the node of the tree that contains a given value. 
//// The traversed tree is considered as a general binary tree.
//// Preconditions: NodeData object to be found and BinTree object to be traversed have 
//// been previously created. BinTree is considered as a general binary tree.
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//int BinTree::findNodeRecursive(const NodeData& toFind, NodeBST* curNode) const
//{
//	if (curNode == NULL) {
//		return 0;
//	}
//	// If item is found in the binary tree return the height of the subtree
//	if (toFind == *curNode->item) {		
//		return getHeightRecursive(curNode);	// curNode is subtree's root
//	}
//	// Else keep looking in left and right subtrees
//	int left = findNodeRecursive(toFind, curNode->left);
//	int right = findNodeRecursive(toFind, curNode->right);
//	return max(left, right);
//}
//
//// -------------------------------getHeightRecursive--------------------------------
//// Helper function to find the height of a node in a general binary tree recursively.
//// Preconditions: NodeBST object has been identified in findNodeRecursive(). 
//// The height of a node at a leaf is 1, if not found is 0.
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//int BinTree::getHeightRecursive(NodeBST* curNode) const
//{
//	if (curNode == NULL) {
//		return 0;
//	}
//	// Find the height of the left subtree in current tree node
//	int subtreeLeft = getHeightRecursive(curNode->left);
//	// Find the height of the right subtree in current tree node
//	int subtreeRight = getHeightRecursive(curNode->right);
//	// Return height of current node + the height of heighest subtree
//	return 1 + max(subtreeLeft, subtreeRight);
//}
//
//// ------------------------------bstreeToArray-------------------------------------
//// Function to fill an array of Nodedata* by using inorderToArray(), an inorder 
//// traversal of the tree helper function.
//// Preconditions: BinTree object has been previously created.
//// Postconditions: BinTree object is left empty and each element of the array NodeData*
//// is pointing to the memory address of each NodeData in the binary tree.
//// --------------------------------------------------------------------------------
//void BinTree::bstreeToArray(NodeData* arrayBST[])
//{
//	// Traverse tree in order to copy NodeData* elements to arrayBST 
//	inorderToArray(root, arrayBST, 0);
//}
//
//// -------------------------------inorderToArray-----------------------------------
//// Function to recursively traverse binary tree in order. Helper function of arrayToBSTree().
//// Preconditions: BinTree object and NodeData array have been previously created.
//// Postconditions: BinTree object is left empty and each element of the array NodeData*
//// is pointing to the memory address of each NodeData in the binary tree. 
//// --------------------------------------------------------------------------------
//void BinTree::inorderToArray(NodeBST*& curNode, NodeData* arrayBST[], int pos)const
//{
//	// If the tree is empty, return
//	if (curNode == NULL) {
//		return;
//	}
//	// Else traverse the tree and append current node item to the end of vector output
//	inorderToArray(curNode->left, arrayBST, pos);
//	// Next available position in array (NULL) stores memory address of current bstNode
//	int i = 0;
//	while (i < 100 && arrayBST[i] != NULL) {
//		i++;
//	}
//	arrayBST[i] = curNode->item;
//	inorderToArray(curNode->right, arrayBST, pos);
//	// Remove bstNode pointer from tree and only keep NodeData pointer in array pointing
//	// to NodeData memory address.
//	delete curNode;
//	curNode = NULL;
//}
//
//// -------------------------------arrayToBSTree------------------------------------
//// Function to build a balanced BinTree from a sorted array of NodeData* leaving the
//// array filled with NULLs.
//// Preconditions: BinTree object and NodeData array have been previously created.
//// Postconditions: Array of NodeData* is filled with NULLs and NodeData in each 
//// NodeBST of BinTree is now pointing to the memory address of each NodeData that 
//// was in the array.
//// --------------------------------------------------------------------------------
//void BinTree::arrayToBSTree(NodeData* arrayBST[])
//{
//	int index = 0;
//	// Clear out previous tree
//	makeEmpty();
//	// Determine the end of the sorted data
//	while (arrayBST[index] != NULL) {
//		index++;
//	}
//	// At the end of the while loop, index is now one beyond the sorted data
//	root = arrayToBSTHelper(arrayBST, 0, index - 1);
//	// Make array values null
//	for (int i = 0; i < index + 1; i++) {
//		arrayBST[i] = NULL;
//	}
//}
//
////----------------------------arrayToBSTHelper-------------------------------------
//// Helper function for arrayToBST().Recursively inserts array elements to make a 
//// balanced tree.
//// Preconditions: BinTree object and NodeData array have been previously created.
//// Postconditions: Array of NodeData* is filled with NULLs and NodeData in each 
//// NodeBST of BinTree is now pointing to the memory address of each NodeData that 
//// was in the array.
////---------------------------------------------------------------------------------
//NodeBST* BinTree::arrayToBSTHelper(NodeData* arrayBST[], int start, int end)
//{
//	// Base case
//	if (start > end) {
//		return NULL;
//	}
//	int midpoint = (start + end) / 2;
//	// Add new node 
//	NodeBST *curNode = new NodeBST;
//	curNode->item = arrayBST[midpoint];
//	curNode->left = NULL;
//	curNode->right = NULL;
//	// Move down left of currNode
//	curNode->left = arrayToBSTHelper(arrayBST, start, midpoint - 1);
//	// Move down right of currNode
//	curNode->right = arrayToBSTHelper(arrayBST, midpoint + 1, end);
//
//	return curNode;
//}
//
////---------------------------- displaySideways ------------------------------------
//// Displays a binary tree as though you are viewing it from the side;
//// hard coded displaying to standard output.
//// Preconditions: NONE
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//void BinTree::displaySideways() const
//{
//	sideways(root, 0);
//}
//
////------------------------------- Sideways ----------------------------------------
//// Helper method for displaySideways
//// Preconditions: NONE
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//void BinTree::sideways(NodeBST* current, int level) const
//{
//	if (current != NULL) {
//		level++;
//		sideways(current->right, level);
//		// Indent for readability, 4 spaces per depth level 
//		for (int i = level; i >= 0; i--) {
//			cout << "    ";
//		}
//
//		cout << *current->item << endl;        // Display information of object
//		sideways(current->left, level);
//	}
//}
//
//// --------------------------------isEmpty-----------------------------------------
//// Function to know if a tree is empty.
//// Preconditions: NONE
//// Postconditions: BinTree remains unchanged.
//// --------------------------------------------------------------------------------
//bool BinTree::isEmpty() const
//{
//	return root == NULL;
//}
//
//// -----------------------------makeEmpty------------------------------------------
//// Make the tree empty so isEmpty returns true. Uses removeHelper private function.
//// Preconditions: BinTree object previously created.
//// Postconditions: BinTree is left empty.
//// --------------------------------------------------------------------------------
//void BinTree::makeEmpty()
//{
//	removeHelper(root);
//	root = NULL;	// Set root to NULL after removing all tree nodes.
//}

// ----------------------------------removeHelper----------------------------------
// Helper method to empty a binary search tree using postorder traversal 
// (left, right, visit).
// Preconditions: BinTree object previously created.
// Postconditions: BinTree is left empty.
// --------------------------------------------------------------------------------
void BinTree::removeHelper(NodeBST* toRemove)
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
bool BinTree::insert(Movie*& newData)
{
	//return true;
	return insertRecursive(root, newData);
}

 //--------------------------insertRecursive---------------------------------------
 //Recursive function to insert a new node in the tree.
 //Preconditions: NodeData* previously created to be inserted in BinTree.
 //Postconditions: BinTree has a new NodeBST.
 //--------------------------------------------------------------------------------
bool BinTree::insertRecursive(NodeBST*& curNode, Movie*& newData)
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
