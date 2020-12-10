/*
  Name: Brayan Chacha Gonzalez
  zID: z1861700
  Course: CSCI 340 Data Structures

*/

#ifndef H_BINTREE
#define H_BINTREE

// Including node header
#include "node.h"

// Declaring class binTree 
template < class T > class binTree;

template <typename T> class binTree{
public:
    binTree(){ root = NULL; };                      // default constructor
    unsigned size() const;                          // returns size of tree
    unsigned height() const;                        // returns height of tree
    virtual void insert(const T&);                  // inserts node in tree
    void inorder(void (*)(const T&));               // inorder traversal of tree

    // Left or Right - Location of where the nodes will placed
    // Even #'s go --- right
    // Odd  #'s go --- left 
    typedef enum {leftSide, rightSide} SIDE;
    SIDE rnd() {return rand() % 2 ? rightSide : leftSide; }

protected:
    Node<T> *root;                                  // root of tree
    
private:
    unsigned size(Node<T> *) const;                 // private version of size()
    unsigned height(Node<T> *) const;               // private version of height() 
    void insert(Node<T> *&, const T&);              // private version of insert() 
    void inorder(Node<T> *, void (*)(const T&));    // private version of inorder()
};

// *******************************************************************************
// *********************  P U B L I C  T E M P L A T E S *************************
// *******************************************************************************

// Public - size() === Will return the size of the tree
template <class T>
unsigned binTree<T>::size() const 
{
	return size(root);
}

// Public - height() --- Will return the height of the tree
template <class T> 
unsigned binTree<T>::height() const
{
	return height(root);
}

// Public - inorder() --- Pointing to a function inorder(void(*func) 
// 			  Calling private inorder
template<class T> 
void binTree<T>::inorder(void(*func) (const T&)) 
{
	inorder(root, func);
}

// Public - insert() --- element, reference const T& element 
// 			 Calling private insert()	
template <class T> 
void binTree<T>::insert(const T& element)
{
	insert(root,element);
}

// *********************************************************************************
// ********************* P R I V A T E  T E M P L A T E S **************************
// *********************************************************************************

// Private - size() --- pointer to a Node to <class T> 
template <class T>
unsigned binTree<T>::size(Node<T>* ptr) const 
{
	// Return 0, if NULL
	if (ptr == NULL)
		return 0;

	// Return the size of the Tree
	return(size(ptr->left) + 1 + size(ptr->right));
}

// Private - height() --- pointer to a node to <class T> 
template <class T>
unsigned binTree<T>::height(Node<T>* ptr) const 
{
	// Return 0, if no Tree
	if (!ptr)
		return 0;

	// Return height of the Tree
	return 1 + max(height(ptr->left), height(ptr->right));
}


// Private - insert() --- pointer to a node to <class T>,
// 			  adds the items to the tree, here we ether create a new node or
// 			  set right or left side to NULL along to deciding to make a new
// 			  node using rnd() 
template<class T>
void binTree<T>::insert(Node<T>*& ptr, const T& element)
{
	if (ptr == NULL)
	{
		// Pointer to Node<T>, Creatinga new Node
		ptr = new Node<T>();
		
		// Placement to the right = NULL
		ptr->right = NULL;

		// Placement to the left = NULL
		ptr->left = NULL;

	
		ptr->data = element;
	}

	// Creating a new element using rnd() and inserting it to Tree
	else if (rnd() == rightSide)
		insert(ptr->right, element);
	else 
		insert(ptr->left, element);	
}


// Private - inorder() --- pointer to a node to <class T>, here we use recursion to 
// 			   go through the Tree
template <class T>
void binTree<T>::inorder(Node<T>* ptr, void(*func) (const T&))
{
	if (ptr != NULL) 
	{
		inorder(ptr->left, func);
		func(ptr->data);
		inorder(ptr->right, func);
		
	}

}
#endif
