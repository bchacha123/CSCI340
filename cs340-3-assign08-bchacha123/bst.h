/* 
   Name: Bryan Chacha 
   Assi: Assignment08
   date: 4/13/20

 */
#ifndef BST_H
#define BST_H

// Adding header file binTree
#include "binTree.h"


template <typename T>
class binSTree : public binTree <T>
{

	public:
		void insert(const T &x);		// inserts node with value x
		bool search(const T &x) const;		// searches lead with value x
		bool remove(const T &x);

	private:
		void insert(Node<T> *&, const T &);		// private version of insert
		bool search(Node<T> *, const T &) const;	// private version of search
		Node <T>* remove (Node <T>*, const T&);		// private version of remove 
		bool leaf(Node<T> *node) const;			// checks if node if leaf
};

// ******************************************************************************************
// **************************  P U B L I C  T E M P L A T E  ********************************
// ******************************************************************************************

// public insert() - >  inserts a node with the data value in x in the tree
template<typename T>
void binSTree<T>::insert ( const T& x)
{
	// passing the root as an argument 
	insert(this->root, x);
	
}

// public search() - > searches leaf with respected to x 
template<typename T>
bool binSTree<T>::search ( const T& x) const
{
	return search( this->root, x);
}

// public remove() - > removes the leaf respect to x
template<typename T>
bool binSTree<T>::remove ( const T &x)
{
	// if the size is equal to 1 the root is set to null
	if(this->size() == 1){

		// Setting it to 0
		this->root = NULL;

		return false;
	}

	if(this->size() > 1)
	{
		// determining the results of the search function respect to x 
		if (search(x)) this->root = remove( this->root,x );
		
		// Success, calling the private version remove()
		return true;

	}
	// else, size == 1
	else if (this->size() == 1)
	{
		return false;
	}

	else
	{
		return false;
	}

}

// ******************************************************************************************
// ************************ P R I V A T E  T E M P L A T E S ********************************
// ******************************************************************************************

// implementing the private version of insert()
// insert- insert a new node 
template<typename T>
void binSTree<T>::insert( Node <T>*& p, const T& v)
{
	// binTreeNode - p 
	if (p == NULL)
	{
		// new node is created if p is set to 0
		p = new Node<T>( v );
	}

	else if (v < p ->data)
	{
		// inserting to the left side of the node 
		insert(p->left, v);

	}

	else if( v > p->data )
	{	// inserting  to the right side of the node
		insert( p->right, v);
	}

	else 
	{
		// returning -> double
		return;
	}
}

// Implementing the private version of search
// p is the data value of the leaf to be searched for 
template<typename T>
bool binSTree<T>::search(Node <T>* p, const T& v) const
{
	
	// p is empty return false 
	if ( p == NULL ) return false;

	else{
		if ( v == p->data )
		{
			if(leaf(p)) return true;
			else return false; 
		}
		
		// searching left
		else if (v < p->data)

		return search (p ->left, v);

		// searching right
		else return search (p->right, v);

	}
}

// Implementing the private verstion of remove 
// remove - deltes the key and returns the new root 
template<typename T>
Node<T>* binSTree<T>::remove (Node <T>* p, const T& v)
{

	// Current node 
	Node<T>* curr;
	// Parent node
	Node<T>* parent;

	curr = p;
	
	// while current is NOT empty
	while (curr != NULL)

	{
		// data inserted in the tree, base case
		if( curr->data == v)
		{
			break;
		}

		else {
			// current is the parent
			parent = curr;
			
			// if v is greater than curr->data lies right
			if ( v > curr->data ) curr = curr->right;
			
			// or left
			else curr = curr->left;
	
		}

	}
		// Current is NOT empty
		if( curr != NULL)
		{
			// parent to theh right is curr set to NULL
			if ( parent->right == curr ) parent->right = NULL;
			
			// left parent set to NLL
			else parent->left = NULL;
			
			// set it to delete or NULL
			delete curr;

			curr = NULL;
		}

		if (this->size() >= 1){
			return this->root;
		}

		return this->root;

}

// Implementing the private version of lear
// checks if node if a leaf
template<typename T>
bool binSTree<T>::leaf ( Node <T>* p ) const 
{
	// settin left and right NULL
	if (p->left == NULL && p->right == NULL)
	{
		return true;
	}
	else{
		return false;
	}

}
#endif
