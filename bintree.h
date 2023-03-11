// ------------------------------------------------ bintree.h -------------------------------------------------------
// Kelly M. Kauffman					CSS502 A
// Brenda S. Vega Contreras 
// Creation Date : 1/16/2023
// Date of Last Modification: 1/25/2023
// ---------------------------------------------------------------------------------------------------------------
// Purpose: Declaration file for a binary search tree class 
// ---------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
//	- Implemented using NodeData object
//  - getHeight() can solve the height of any type of binary tree, not just a binary search tree
// 
// Assumptions:
// -Trees are built as binary search trees, except for arrayToBSTree() that builds a balanced binary tree
// -Nodes of a tree are linked together using pointers
// -Trees that are empty are equal
// -Height of a node at a leaf is 1
// -The height of a value not found is 0
// ---------------------------------------------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include "movie.h"
#include <vector>

struct NodeBST		// Node in tree that holds item, left and right children of it.
{
	Movie* item;		// Pointer to item object
	NodeBST* left;		// Left subtree pointer
	NodeBST* right;		// Right subtree pointer
};

class BinTree
{
	// --------------------------------------------------------------------------------
	// Overload of operator<<
	// Method to display the tree using inorder traversal.
	// --------------------------------------------------------------------------------
	friend ostream& operator<<(ostream&, const BinTree&);

public:
	// --------------------------------------------------------------------------------
	// Default constructor
	// Creates an empty tree
	// --------------------------------------------------------------------------------
	BinTree();

	// --------------------------------------------------------------------------------
	// Copy constructor
	// Makes a deep copy of the right hand side binary tree into the left hand side 
	// binary tree.
	// --------------------------------------------------------------------------------
	BinTree(const BinTree&);

	// --------------------------------------------------------------------------------
	// Destructor
	// Destructor for class BinTree
	// --------------------------------------------------------------------------------
	~BinTree();

	// --------------------------------------------------------------------------------
	// Overload of operator=
	// Overloaded assignment operator. Makes a deep copy to assign one tree to another.
	// --------------------------------------------------------------------------------
	const BinTree& operator=(const BinTree&);

	// --------------------------------------------------------------------------------
	// Overload of operator==
	// Define two trees to be equal if they have the same data and same structure.
	// --------------------------------------------------------------------------------
	bool operator==(const BinTree&) const;

	// --------------------------------------------------------------------------------
	// Overload of operator!=
	// Determine if two binary treeas are not equal.
	// --------------------------------------------------------------------------------
	bool operator!=(const BinTree&) const;

	// --------------------------------------------------------------------------------
	// Retrieve function
	// Function to get the NodeData* of a given object in the tree (via pass-by-reference
	// parameter) and to report whether the object is found(true or false).
	// --------------------------------------------------------------------------------
	bool retrieve(const NodeData&, NodeData*&);

	// --------------------------------------------------------------------------------
	// getHeight function
	// Function to find the height of a given value in the tree.
	// --------------------------------------------------------------------------------
	int getHeight(const NodeData&) const;

	// --------------------------------------------------------------------------------
	// bstreeToArray function
	// Function to fill an array of Nodedata* by using an inorder traversal of the tree.
	// --------------------------------------------------------------------------------
	void bstreeToArray(NodeData* []);

	// --------------------------------------------------------------------------------
	// arrayToBSTree function
	// Function to build a balanced BinTree from a sorted array of NodeData* leaving the
	// array filled with NULLs.
	// --------------------------------------------------------------------------------
	void arrayToBSTree(NodeData* []);

	// --------------------------------------------------------------------------------
	// displaySideways function
	// Function for helping display a binary tree as if you are viewing it from the side.
	// --------------------------------------------------------------------------------
	void displaySideways() const;

	// --------------------------------------------------------------------------------
	// isEmpty function
	// Function to know if a tree is empty.
	// --------------------------------------------------------------------------------
	bool isEmpty() const;

	// --------------------------------------------------------------------------------
	// makeEmpty function
	// Make the tree empty so isEmpty returns true
	// --------------------------------------------------------------------------------
	void makeEmpty();

	// --------------------------------------------------------------------------------
	// Insert function
	// Function to insert a new node in the tree.
	// --------------------------------------------------------------------------------
	bool insert(NodeData*&);

	// --------------------------------------------------------------------------------
	// Insert function
	// Function to insert a new node in the tree.
	// --------------------------------------------------------------------------------
	bool insert(Movie*&);


private:
	NodeBST* root;		// Root node of the tree.

	// --------------------------------------------------------------------------------
	// Insert function
	// Function to insert a new node in the tree.
	// --------------------------------------------------------------------------------
	bool insertRecursive(NodeBST*&, Movie*&);

	// --------------------------------------------------------------------------------
	// inorderHelper function
	// Function to traverse binary tree in order. Helper method to overload << operator.
	// --------------------------------------------------------------------------------
	void inorderHelper(NodeBST*, ostream&)const;

	// --------------------------------------------------------------------------------
	// findNodeRecursive
	// Helper function to find the node of the tree that contains a given value. 
	// The traversed tree is considered as a general binary tree.
	// --------------------------------------------------------------------------------
	int findNodeRecursive(const NodeData&, NodeBST*) const;
	
	// --------------------------------------------------------------------------------
	// getHeightRecursive
	// Helper function to find the height of a general binary tree recursively.
	// --------------------------------------------------------------------------------
	int getHeightRecursive(NodeBST*) const;
	
	// --------------------------------------------------------------------------------
	// inorderToArray function
	// Function to traverse binary tree in order. Helper method of arrayToBSTree(). 
	// --------------------------------------------------------------------------------
	void inorderToArray(NodeBST*&, NodeData* [], int)const;

	// --------------------------------------------------------------------------------
	// inorderHelper function
	// Helper for displaySideways() function.
	// --------------------------------------------------------------------------------
	void sideways(NodeBST*, int) const;

	// --------------------------------------------------------------------------------
	// Copy function
	// Makes a deep copy of right hand side polynomial into left hand side polynomial.
	// Used as helper for assignment operator method and copy constructor.
	// --------------------------------------------------------------------------------
	NodeBST* copy(const NodeBST*);

	// --------------------------------------------------------------------------------
	// Remove helper function
	// Helper method to remove all nodes of a binary search tree using postorder traversal.
	// --------------------------------------------------------------------------------
	void removeHelper(NodeBST*);

	// --------------------------------------------------------------------------------
	// retrieveRecursive function
	// Helper function for retrieve(). Uses recursion to find a given object.
	// --------------------------------------------------------------------------------
	bool retrieveRecursive(NodeBST*, const NodeData&, NodeData*&);

	// --------------------------------------------------------------------------------
	// arrayToBSTHelper function
	// Helper function for arrayToBST(). Recursively inserts array elements to make a balanced tree.
	// --------------------------------------------------------------------------------
	NodeBST* arrayToBSTHelper(NodeData* [], int, int);

	// --------------------------------------------------------------------------------
	// compare function
	// Helper function for operator == and operator !=().
	// --------------------------------------------------------------------------------
	bool compare(NodeBST*, NodeBST*) const;
};
#endif

